void plot(){

  // opening files
  TFile f1("out_dat.root");
  TFile f2("out_sig.root");
  TFile f3("out_bkg.root");

  // get histograms from the files  
  TH1F * h_x_1 = (TH1F*)f1.Get("h_x");
  TH1F * h_x_2 = (TH1F*)f2.Get("h_x");
  TH1F * h_x_3 = (TH1F*)f3.Get("h_x");

  // set line colors
  h_x_1->SetLineColor(1);
  h_x_2->SetLineColor(2);
  h_x_3->SetLineColor(4);
  
  
  // get histograms from one signal MC to compare
  TH1F * h_x_electron = (TH1F*)f2.Get("h_x_electron");
  TH1F * h_x_positron = (TH1F*)f2.Get("h_x_positron");
  h_x_electron->SetLineColor(1);
  h_x_positron->SetLineColor(2);
  //normalization to 1
  h_x_electron->Scale(1./h_x_electron->GetEntries());
  h_x_positron->Scale(1./h_x_positron->GetEntries());
  
  TH1F * h_x_y_1 = (TH1F*)f1.Get("h_x_y");
  TH1F * h_x_y_2 = (TH1F*)f2.Get("h_x_y");
  TH1F * h_x_y_3 = (TH1F*)f3.Get("h_x_y");

  TCanvas c; 
  c.SaveAs("plots.pdf["); // opening pdf

/*  // draw all histograms
  h_x_1->Draw("e");
  h_x_2->Draw("same");
  h_x_3->Draw("same");
  c.SaveAs("plots.pdf"); // plot

  //next plot
  c.Clear();
  h_x_electron->Draw("hist");
  h_x_positron->Draw("hist same");
  c.SaveAs("plots.pdf");

  // next plot
  c.Clear();
  c.Divide(3);
  c.cd(1); h_x_y_1->Draw("colz");
  c.cd(2); h_x_y_2->Draw("colz");
  c.cd(3); h_x_y_3->Draw("colz");
  c.SaveAs("plots.pdf");
*/
  gStyle->SetOptStat(0);//no stat box
  
//properties of mu_like for muons and other particles
  c.Clear();
  //we must use MC, since in data we obviously do not have mu_id
  //one can and in fact should cross-check if properties of muons in signal and bg samples are the same
  //I've checked this beforehand -> here only plot for MC signal is plotted
  TH1F * h_mu_like_notmuon = (TH1F*)f2.Get("h_mu_like_notmuon");
  TH1F * h_mu_like_muon = (TH1F*)f2.Get("h_mu_like_muon");
  gPad->SetLogy(1); //log scale
  h_mu_like_notmuon->Scale(1./h_mu_like_notmuon->GetEntries()); //normalization to 1
  h_mu_like_muon->Scale(1./h_mu_like_muon->GetEntries());
  h_mu_like_notmuon->SetLineColor(1);
  h_mu_like_muon->SetLineColor(2);
  h_mu_like_notmuon->Draw("hist");
  h_mu_like_muon->Draw("hist same");
  float ymax = h_mu_like_notmuon->GetMaximum();
  float ymin = h_mu_like_notmuon->GetMinimum();
  TLine *l1 = new TLine(0.7,ymin,0.7,ymax);
  l1->SetLineColor(4);
  l1->SetLineWidth(3);
  l1->Draw("same");
  c.SaveAs("plots.pdf");

//cuts only MC is relevant
//pT of muons
  c.Clear();
  TH1F * h_pT_pos_2 = (TH1F*)f2.Get("h_pT_pos");
  TH1F * h_pT_pos_3 = (TH1F*)f3.Get("h_pT_pos");
  gPad->SetLogy(0); //unset log scale
  h_pT_pos_2->Scale(1./h_pT_pos_2->GetEntries());
  h_pT_pos_3->Scale(1./h_pT_pos_3->GetEntries());
  h_pT_pos_2->SetLineColor(1);
  h_pT_pos_3->SetLineColor(2);
  h_pT_pos_2->SetMaximum(0.15);
  h_pT_pos_2->Draw("hist");
  h_pT_pos_3->Draw("hist same");
  ymax = h_pT_pos_2->GetMaximum();
  ymin = h_pT_pos_2->GetMinimum();
  TLine *l2 = new TLine(7.,ymin,7.,ymax);
  l2->SetLineColor(4);
  l2->SetLineWidth(3);
  l2->Draw("same");
  TLine *l3 = new TLine(14.,ymin,14.,ymax);
  l3->SetLineColor(4);
  l3->SetLineWidth(3);
  l3->Draw("same");
  c.SaveAs("plots.pdf");

  c.Clear();
  TH1F * h_pT_neg_2 = (TH1F*)f2.Get("h_pT_neg");
  TH1F * h_pT_neg_3 = (TH1F*)f3.Get("h_pT_neg");
  gPad->SetLogy(0); //unset log scale
  h_pT_neg_2->Scale(1./h_pT_neg_2->GetEntries());
  h_pT_neg_3->Scale(1./h_pT_neg_3->GetEntries());
  h_pT_neg_2->SetLineColor(1);
  h_pT_neg_3->SetLineColor(2);
  h_pT_neg_2->SetMaximum(0.15);
  h_pT_neg_2->Draw("hist");
  h_pT_neg_3->Draw("hist same");
  l2->Draw("same");
  l3->Draw("same");
  c.SaveAs("plots.pdf");
//z vertex distance
  c.Clear();
  TH1F * h_z_2 = (TH1F*)f2.Get("h_z");
  TH1F * h_z_3 = (TH1F*)f3.Get("h_z");
  gPad->SetLogy(1);
  h_z_2->Scale(1./h_z_2->GetEntries());
  h_z_3->Scale(1./h_pT_neg_3->GetEntries());
  h_z_2->SetLineColor(1);
  h_z_3->SetLineColor(2);
  h_z_2->SetMaximum(0.15);
  h_z_2->Draw("hist");
  h_z_3->Draw("hist same");
  ymax = h_z_2->GetMaximum();
  ymin = h_z_2->GetMinimum();
  TLine *l4 = new TLine(0.015,ymin,0.015,ymax);
  l4->SetLineColor(4);
  l4->SetLineWidth(3);
  l4->Draw("same");
  TLine *l5 = new TLine(-0.015,ymin,-0.015,ymax);
  l5->SetLineColor(4);
  l5->SetLineWidth(3);
  l5->Draw("same");
  c.SaveAs("plots.pdf");
//azimuthal angle between muons
  c.Clear();
  TH2F * h_phi_pos_vs_phi_neg_2 = (TH2F*)f2.Get("h_phi_pos_vs_phi_neg");
  TH2F * h_phi_pos_vs_phi_neg_3 = (TH2F*)f3.Get("h_phi_pos_vs_phi_neg");
  gPad->SetLogy(0);
  h_phi_pos_vs_phi_neg_2->Scale(1./h_phi_pos_vs_phi_neg_2->GetEntries());
  h_phi_pos_vs_phi_neg_3->Scale(1./h_phi_pos_vs_phi_neg_3->GetEntries());
  c.Divide(2);
  c.cd(1);
  h_phi_pos_vs_phi_neg_2->Draw("colz");
  c.cd(2);
  h_phi_pos_vs_phi_neg_3->Draw("colz same");
  c.SaveAs("plots.pdf");

  c.Clear();
  TH1F * h_phi_diff_2 = (TH1F*)f2.Get("h_phi_diff");
  TH1F * h_phi_diff_3 = (TH1F*)f3.Get("h_phi_diff");
  gPad->SetLogy(1);
  h_phi_diff_2->Scale(1./h_phi_diff_2->GetEntries());
  h_phi_diff_3->Scale(1./h_phi_diff_3->GetEntries());
  h_phi_diff_2->SetLineColor(1);
  h_phi_diff_3->SetLineColor(2);
  h_phi_diff_2->SetMaximum(0.15);
  h_phi_diff_2->Draw("hist");
  h_phi_diff_3->Draw("hist same");
  ymax = h_phi_diff_2->GetMaximum();
  ymin = h_phi_diff_2->GetMinimum();
  TLine *l6 = new TLine(2.3,ymin,2.3,ymax);
  l6->SetLineColor(4);
  l6->SetLineWidth(3);
  l6->Draw("same");
  TLine *l7 = new TLine(4.2,ymin,4.2,ymax);
  l7->SetLineColor(4);
  l7->SetLineWidth(3);
  l7->Draw("same");
  c.SaveAs("plots.pdf");

//invariant mass
//no cuts
  c.Clear();
  TH1F * h_m_1 = (TH1F*)f1.Get("h_m");//we need data now!
  TH1F * h_m_2 = (TH1F*)f2.Get("h_m");
  TH1F * h_m_3 = (TH1F*)f3.Get("h_m");
  gPad->SetLogy(1);
//normalization according to instruction:
//- data events (integrated luminosity: 100 nb −1 ),
//- signal events generated according to a model (cross section: 500 nb),
//- background events generated according to a model (cross section: 5 nb).

//NOTE: there is an error in the instruction; cross-sections for signal and background are swapped!
  double MC_sigma_sig = 5.;//nb
  double MC_sigma_bkg = 500.;//nb
  double L = 100.; //nb-1
  double n_entries_MC_sig = h_m_2->GetEntries();
  double n_entries_MC_bkg = h_m_3->GetEntries();
  h_m_2->Scale(MC_sigma_sig*L/n_entries_MC_sig);
  h_m_3->Scale(MC_sigma_bkg*L/n_entries_MC_bkg);
  h_m_2->SetLineColor(1);
  h_m_3->SetLineColor(2);  
  h_m_1->SetMaximum(1.e4);
  h_m_1->SetMinimum(1.);
  h_m_1->Draw("Pe");
  h_m_2->Draw("hist same");
  h_m_3->Draw("hist same");
  c.SaveAs("plots.pdf");
//cut on pT
  c.Clear();
  TH1F * h_m_cut1_1 = (TH1F*)f1.Get("h_m_cut1");//we need data now!
  TH1F * h_m_cut1_2 = (TH1F*)f2.Get("h_m_cut1");
  TH1F * h_m_cut1_3 = (TH1F*)f3.Get("h_m_cut1");
  gPad->SetLogy(1);
  h_m_cut1_1->SetMaximum(1.e4);
  h_m_cut1_1->SetMinimum(1.);
//it is important to correctly normalize! (to initial number of events)
  h_m_cut1_2->Scale(MC_sigma_sig*L/n_entries_MC_sig);
  h_m_cut1_3->Scale(MC_sigma_bkg*L/n_entries_MC_bkg);
  h_m_cut1_2->SetLineColor(1);
  h_m_cut1_3->SetLineColor(2);
  h_m_cut1_1->Draw("Pe");
  h_m_cut1_2->Draw("hist same");
  h_m_cut1_3->Draw("hist same");
  c.SaveAs("plots.pdf");

//cut on pT and z
  c.Clear();
  TH1F * h_m_cut2_1 = (TH1F*)f1.Get("h_m_cut2");//we need data now!
  TH1F * h_m_cut2_2 = (TH1F*)f2.Get("h_m_cut2");
  TH1F * h_m_cut2_3 = (TH1F*)f3.Get("h_m_cut2");
  gPad->SetLogy(1);
  h_m_cut2_1->SetMaximum(1.e4);
  h_m_cut2_1->SetMinimum(1.);
//it is important to correctly normalize! (to initial number of events)
  h_m_cut2_2->Scale(MC_sigma_sig*L/n_entries_MC_sig);
  h_m_cut2_3->Scale(MC_sigma_bkg*L/n_entries_MC_bkg);
  h_m_cut2_2->SetLineColor(1);
  h_m_cut2_3->SetLineColor(2);
  h_m_cut2_1->Draw("Pe");
  h_m_cut2_2->Draw("hist same");
  h_m_cut2_3->Draw("hist same");
  c.SaveAs("plots.pdf");

//cut on pT, z and phi
  c.Clear();
  TH1F * h_m_cut3_1 = (TH1F*)f1.Get("h_m_cut3");//we need data now!
  TH1F * h_m_cut3_2 = (TH1F*)f2.Get("h_m_cut3");
  TH1F * h_m_cut3_3 = (TH1F*)f3.Get("h_m_cut3");
  gPad->SetLogy(1);
  h_m_cut3_1->SetMaximum(1.e4);
  h_m_cut3_1->SetMinimum(1.);
//it is important to correctly normalize! (to initial number of events)
  h_m_cut3_2->Scale(MC_sigma_sig*L/n_entries_MC_sig);
  h_m_cut3_3->Scale(MC_sigma_bkg*L/n_entries_MC_bkg);
  h_m_cut3_2->SetLineColor(1);
  h_m_cut3_3->SetLineColor(2);
  h_m_cut3_1->Draw("Pe");
  h_m_cut3_2->Draw("hist same");
  h_m_cut3_3->Draw("hist same");
  c.SaveAs("plots.pdf");

  c.Clear();
  gPad->SetLogy(0);
  h_m_cut3_1->SetMaximum(50.);
  h_m_cut3_1->SetMinimum(0.);
  h_m_cut3_1->Draw("Pe");
  h_m_cut3_2->Draw("hist same");
  h_m_cut3_3->Draw("hist same");
  c.SaveAs("plots.pdf");

  c.SaveAs("plots.pdf]"); // closing pdf
}
