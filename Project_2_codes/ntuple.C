#define ntuple_cxx
#include "ntuple.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <iomanip>
#include <TChain.h>
#include <TLorentzVector.h>

void ntuple::Loop()
{
  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntries();

  TFile output(this->outputFileName.data(), "recreate");
  TH1F h_x("h_x", "", 100, -1e-4, 1e-4);
  TH1F h_x_electron("h_x_electron", "", 100, -1e-4, 1e-4);
  TH1F h_x_positron("h_x_positron", "", 100, -1e-4, 1e-4);
  
  TH2F h_x_y("h_x_y", "", 100, -1e-4, 1e-4, 100, -1e-4, 1e-4);

  //determinig, what is a muon
  TH1F h_mu_like_muon("h_mu_like_muon", "mu like for muons", 100, 0., 1.);
  TH1F h_mu_like_notmuon("h_mu_like_notmuon", "mu like for other particles", 100, 0., 1.);
  
  //distributions
  TH1F h_pT_pos("h_pT_pos", "transverse momentum of mu+", 100, 0., 50.);
  TH1F h_pT_neg("h_pT_neg", "transverse momentum of mu-", 100, 0., 50.);
  TH1F h_z("h_z", "z-distance of muon vertex", 100, -0.15, 0.15);
  TH2F h_phi_pos_vs_phi_neg("h_phi_pos_vs_phi_neg", "correlation between angular momentum of muons", 30, -3., 3., 30, -3., 3.);
  TH1F h_phi_diff("h_phi_diff", "difference of muon angular mementum", 50, 0., 6.5);

  //invariant mass
  TH1F h_m("h_m", "invariant mass no cut", 100, 0., 50.);
  TH1F h_m_cut1("h_m_cut1", "invariant mass after pT cut", 100, 0., 50.);
  TH1F h_m_cut2("h_m_cut2", "invariant mass after pT and z cut", 100, 0., 50.);
  TH1F h_m_cut3("h_m_cut3", "invariant mass after pT, z and phi cut", 100, 0., 50.);

  int cnt = 0;;

  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    fChain->GetEntry(jentry);
      
    TLorentzVector v, v_mu_pos, v_mu_neg, v_sum;
    v_mu_pos.SetPxPyPzE(0., 0., 0., 0.);
    v_mu_neg.SetPxPyPzE(0., 0., 0., 0.);
    int particle_number_mu_pos = -1, particle_number_mu_neg = -1;
    
    int nparticles = id->size();
    for(int particle=0; particle < nparticles; particle++){
      h_x.Fill(x->at(particle));
      h_x_y.Fill(x->at(particle), y->at(particle));
      if (id->at(particle) ==  11) h_x_electron.Fill(x->at(particle));
      if (id->at(particle) == -11) h_x_positron.Fill(x->at(particle));
      
      if (fabs(id->at(particle)) ==  13) //mu+=-13, mu-=13 accordingly to pdgID
      {
        h_mu_like_muon.Fill(mu_like->at(particle));
      }
      else //not muon
      {
        h_mu_like_notmuon.Fill(mu_like->at(particle));
      }
      
      if (mu_like->at(particle) > 0.7) //arbitrary choice; made on h_mu_like_muon and h_mu_like_notmuon distribution comparison
      {
        v.SetPxPyPzE(px->at(particle), py->at(particle), pz->at(particle), e->at(particle)); //setting of TLorentz vector
        //selecting mu+ and mu- with highest pT
        if (fabs(charge->at(particle) - 1.) < 1.e-6) //mu-
        {
          if (v.Pt() > v_mu_neg.Pt()) {v_mu_neg = v; particle_number_mu_neg = particle;} //wyszukanie mionu o największym pedzie poprzecznym
        }
        else if (fabs(charge->at(particle) + 1.) < 1.e-6) //mu+
        {
          if (v.Pt() > v_mu_pos.Pt()) {v_mu_pos = v; particle_number_mu_pos = particle;} 
        }
      }
    }
    
    v_sum = v_mu_pos + v_mu_neg;
    h_m.Fill(v_sum.M());
    if (particle_number_mu_neg == -1 || particle_number_mu_pos == -1) continue; //no muon pair -> nothing to analyse
    
    h_pT_pos.Fill(v_mu_pos.Pt());
    h_pT_neg.Fill(v_mu_neg.Pt());
    
    if (particle_number_mu_neg != -1 && particle_number_mu_pos != -1) h_phi_pos_vs_phi_neg.Fill(v_mu_neg.Phi(), v_mu_pos.Phi());

//note -- selection was not optimized! cut flow below is just an example
     
    if ((v_mu_neg.Pt() > 7.) && (v_mu_pos.Pt() > 7.) && (v_mu_neg.Pt() < 14.) && (v_mu_pos.Pt() < 14.)) //arbitrary cut on muon pT; based on comparison between signal and background distribution; note that background sample was generated for pT > 3.5 GeV -> in region between 1 - 3.5 there is unnaturaly low number of events
    {
      h_m_cut1.Fill(v_sum.M());
      //check of z distribution
      h_z.Fill(z->at(particle_number_mu_neg) - z->at(particle_number_mu_pos));
      
      if (fabs(z->at(particle_number_mu_neg) - z->at(particle_number_mu_pos)) < 0.015) //another cut based on signal - background comparison; cut is symmetric thus fabs
      {
        h_m_cut2.Fill(v_sum.M());
        h_phi_diff.Fill(fabs(v_mu_neg.Phi() - v_mu_pos.Phi()));
        
        if ((fabs(v_mu_neg.Phi() - v_mu_pos.Phi()) > 2.3) && (fabs(v_mu_neg.Phi() - v_mu_pos.Phi()) < 4.2)) //final cut
        {
          h_m_cut3.Fill(v_sum.M());
        }
      }
    }
  }
  
  output.Write();
  output.Close();
}

int main(int argc, char** argv){

  if(argc < 3){
    std::cout << "Usage:\n\t" << argv[0] << " output.root input1.root [input2.root input3.root ...]\n\n";
    return 1;
  }

  std::cout << "Output: " << argv[1] << "\n";
  // TChain is like a TTree, but can work across several root files
  TChain * chain = new TChain("ntuple"); 
  std::cout << "Inputs:\n";
  for(int i=2; i<argc; i++){
    std::cout << "\t" << argv[i] << "\n";
    chain->Add(argv[i]);
  }

  ntuple t(chain);
  t.outputFileName = argv[1];
  t.Loop();

  std::cout << "[ DONE ]\n\n";

}
