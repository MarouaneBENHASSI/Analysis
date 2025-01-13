// 
// Description: 
//

void Drawing_2(){
  TFile *file;
  file = new TFile("merged_v10.root");
  file->ls();
  // TBrowser tb;
  TDirectoryFile * dir1 = (TDirectoryFile*)file->Get("Upc");

  TList * list1 = (TList*)dir1->Get("ListHist");

  TTree * f2Tracks = (TTree*)list1->FindObject("f2Tracks");
  
  TCanvas c; //to use this command, you have to change "->" to "."  
  // TCanvas *c = new TCanvas("c","",400,400); //to use this command, you have to change "." to "->" 

  c.SaveAs("plots.pdf["); // opening pdf                                                                                                         
  /*-------------------------------------------*/
  // Cuts
  /*-------------------------------------------*/
  TCut cut1 = "fTriggers[0] == 1 || fTriggers[1] == 1 || fTriggers[2] == 1" ;
  TCut cut2 = "fTriggers[3] == 1 || fTriggers[4] == 1 && fTriggers[7] == 1" ;
  TCut cut3 = "fTriggers[8] == 1 && fTriggers[5] == 1 || fTriggers[6] == 1" ;
  TCut cut4 = "sqrt ( fZNAenergy * fZNAenergy + fZNCenergy * fZNCenergy ) < 1000" ;
  TCut cut5 = "sqrt( (fZNAenergy-2500) * (fZNAenergy-2500) + fZNCenergy * fZNCenergy) < 1000";
  TCut cut6 = "sqrt( (fZNCenergy-2250) * (fZNCenergy-2250) + fZNAenergy * fZNAenergy ) < 1000";
  TCut cut7 = "sqrt ( fZPAenergy * fZPAenergy + fZPCenergy * fZPCenergy ) < 1000";
  TCut cut8 = "sqrt( (fZPAenergy-2250) * (fZPAenergy-2250) + fZPCenergy*fZPCenergy) < 1000";
  TCut cut9 = "sqrt( (fZPCenergy-2166) * (fZPCenergy-2166) + fZPAenergy*fZPAenergy) < 1000";
  TCut cut10 = "fADAdecision == 0 || fADCdecision == 0" ;
  TCut cut11 = "fV0Adecision == 0 || fV0Cdecision == 0" ;
  TCut cut12 = "abs(fVertexZ) < 10";
  TCut cut13 = "fSign == 1" ;
  TCut cut14 = "fSign == -1" ;
  TCut cut15 = "fM != 0" ;
  TCut cut16 = "sqrt(fnsigTPCMuon * fnsigTPCMuon + (fnsigTPCElectron + 5) * (fnsigTPCElectron + 5)) < 2." ;
  TCut cut17 = "sqrt(fnsigTPCPion * fnsigTPCPion + (fnsigTPCProton + 12) * (fnsigTPCProton + 12)) < 4";
  TCut cut18 = "sqrt((fnsigTPCElectron + 5) * (fnsigTPCElectron + 5) + (fnsigTPCProton + 12) * (fnsigTPCProton + 12)) < 2";
  TCut cut19 = "sqrt(fnsigTPCMuon * fnsigTPCMuon + fnsigTPCPion * fnsigTPCPion) < 4";
  TCut cut20 = "abs(fEtaDaughter) < 0.9";
  
  
  /*-------------------------------------------*/
  // fZNAenergy VS fZNCenergy
  /*-------------------------------------------*/
  // fZNAenergy_fZNCenergy with no selection
  TH2F *ZNA_ZNC = new TH2F("ZNA_ZNC", "ZNAenergy_ZNCenergy", 100, -2000, 10000, 100, -2000, 10000);
  ZNA_ZNC->GetXaxis()->SetTitle("ZNAenergy");
  ZNA_ZNC->GetYaxis()->SetTitle("ZNCenergy");
  f2Tracks->Draw("fZNCenergy:fZNAenergy>>ZNA_ZNC", cut1 + cut20);    
  gPad->SetLogz(1); // Log scale. to return to the normal scale, change 1 to 0
  ZNA_ZNC->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // the first cut: 0n0n
  TH2F *ZNA_ZNC_0n0n = new TH2F("ZNA_ZNC_0n0n", "ZNAenergy_ZNCenergy_0n0n", 100, -2000, 10000, 100, -2000, 10000);
  ZNA_ZNC_0n0n->GetXaxis()->SetTitle("ZNAenergy");
  ZNA_ZNC_0n0n->GetYaxis()->SetTitle("ZNCenergy");
  f2Tracks->Draw("fZNCenergy:fZNAenergy>>ZNA_ZNC_0n0n", cut4 + cut1 + cut20);
  gPad->SetLogz(1);
  ZNA_ZNC_0n0n->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // the second cut: 1n0n
  TH2F *ZNA_ZNC_1n0n = new TH2F("ZNA_ZNC_1n0n", "ZNAenergy_ZNCenergy_1n0n", 100, -2000, 10000, 100, -2000, 10000);
  ZNA_ZNC_1n0n->GetXaxis()->SetTitle("ZNAenergy");
  ZNA_ZNC_1n0n->GetYaxis()->SetTitle("ZNCenergy");
  f2Tracks->Draw("fZNCenergy:fZNAenergy>>ZNA_ZNC_1n0n", cut5 + cut1 + cut20); 
  gPad->SetLogz(1);
  ZNA_ZNC_1n0n->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // the third cut: 0n1n
  TH2F *ZNA_ZNC_0n1n = new TH2F("ZNA_ZNC_0n1n", "ZNAenergy_ZNCenergy_0n1n", 100, -2000, 10000, 100, -2000, 10000);
  ZNA_ZNC_0n1n->GetXaxis()->SetTitle("ZNAenergy");
  ZNA_ZNC_0n1n->GetYaxis()->SetTitle("ZNCenergy");
  f2Tracks->Draw("fZNCenergy:fZNAenergy>>ZNA_ZNC_0n1n", cut6 + cut1 + cut20);  
  gPad->SetLogz(1);
  ZNA_ZNC_0n1n->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  

  /*------------------------------------------ */
  // fZPAenergy VS fZPCenergy
  /*-------------------------------------------*/
  //ZPAenergy_ZPCenergy with no selection
  TH2F *ZPA_ZPC = new TH2F("ZPA_ZPC", "ZPAenergy_ZPCenergy", 100, -2000, 10000, 100, -2000, 10000);
  ZPA_ZPC->GetXaxis()->SetTitle("ZPAenergy");
  ZPA_ZPC->GetYaxis()->SetTitle("ZPCenergy");
  f2Tracks->Draw("fZPCenergy:fZPAenergy>>ZPA_ZPC", cut1 + cut20);
  gPad->SetLogy(0);
  ZPA_ZPC->Draw("colz");
  c.SaveAs("plots.pdf");  
  c.Clear();
  
  // the first cut: 0n0n
  TH2F *ZPA_ZPC_0n0n = new TH2F("ZPA_ZPC_0n0n", "ZPAenergy_ZPCenergy_0n0n", 100, -2000, 10000, 100, -2000, 10000);
  ZPA_ZPC_0n0n->GetXaxis()->SetTitle("ZPAenergy");
  ZPA_ZPC_0n0n->GetYaxis()->SetTitle("ZPCenergy");
  f2Tracks->Draw("fZPCenergy:fZPAenergy>>ZPA_ZPC_0n0n", cut7 + cut1 + cut20);
  gPad->SetLogy(0);
  ZPA_ZPC_0n0n->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // the second cut: 1n0n                                                      
  TH2F *ZPA_ZPC_1n0n = new TH2F("ZPA_ZPC_1n0n", "ZPAenergy_ZPCenergy_1n0n", 100, -2000, 10000, 100, -2000, 10000);
  ZPA_ZPC_1n0n->GetXaxis()->SetTitle("ZPAenergy");
  ZPA_ZPC_1n0n->GetYaxis()->SetTitle("ZPCenergy");
  f2Tracks->Draw("fZPCenergy:fZPAenergy>>ZPA_ZPC_1n0n", cut8 + cut1 + cut20);
  gPad->SetLogy(0);
  ZPA_ZPC_1n0n->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // the third cut: 0n1n                                                      
  TH2F *ZPA_ZPC_0n1n = new TH2F("ZPA_ZPC_0n1n", "ZPAenergy_ZPCenergy_0n1n", 100, -2000, 10000, 100, -2000, 10000);
  ZPA_ZPC_0n1n->GetXaxis()->SetTitle("ZPAenergy");
  ZPA_ZPC_0n1n->GetYaxis()->SetTitle("ZPCenergy");
  f2Tracks->Draw("fZPCenergy:fZPAenergy>>ZPA_ZPC_0n1n", cut9 + cut1 + cut20);
  gPad->SetLogy(0);
  ZPA_ZPC_0n1n->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();   
  
  
  /*------------------------------------------ */
  // fVertexZ 
  /*-------------------------------------------*/
  // fVertexZ with no selection
  TH1F *VertZ = new TH1F("VertZ","fVertexZ", 100, -15, 15);
  VertZ->GetXaxis()->SetTitle("fVertexZ");
  f2Tracks->Draw("fVertexZ>>VertZ", cut20);
  gPad->SetLogy(0);
  gPad->SetLogz(0);
  VertZ->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // fVertexZ + 0n0n
  TH1F *VertZ_0n0n = new TH1F("VertZ_0n0n","fVertexZ_0n0n", 100, -15, 15);
  VertZ_0n0n->GetXaxis()->SetTitle("fVertexZ");
  f2Tracks->Draw("fVertexZ>>VertZ_0n0n", cut4 + cut7 + cut20);
  VertZ_0n0n->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // fVertexZ + 1n0n
  TH1F *VertZ_1n0n = new TH1F("VertZ_1n0n","fVertexZ_1n0n", 100, -15, 15);
  VertZ_1n0n->GetXaxis()->SetTitle("fVertexZ");
  f2Tracks->Draw("fVertexZ>>VertZ_1n0n", cut5 + cut8 + cut20);  
  VertZ_1n0n->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // fVertexZ + 0n1n
  TH1F *VertZ_0n1n = new TH1F("VertZ_0n1n","fVertexZ_0n1n", 100, -15, 15);
  VertZ_0n1n->GetXaxis()->SetTitle("fVertexZ");
  f2Tracks->Draw("fVertexZ>>VertZ_0n1n", cut6 + cut9 + cut20);
  VertZ_0n1n->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // fVertexZ + ADA & ADC
  TH1F *VertZ_AD = new TH1F("VertZ_AD","fVertexZ_AD", 100, -15, 15);
  VertZ_AD->GetXaxis()->SetTitle("fVertexZ");
  f2Tracks->Draw("fVertexZ>>VertZ_AD", cut10 + cut20);
  VertZ_AD->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // fVertex + V0A & V0C
  TH1F *VertZ_V0 = new TH1F("VertZ_V0","fVertexZ_V0", 100, -15, 15);
  VertZ_V0->GetXaxis()->SetTitle("fVertexZ");
  f2Tracks->Draw("fVertexZ>>VertZ_V0", cut11 + cut20);
  VertZ_V0->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // fVertex + ADA & ADC + V0A & V0C 
  TH1F *VertZ_AD_V0 = new TH1F("VertZ_AD_V0","fVertexZ ADA & ADC and V0A & V0C selections", 100, -15, 15);
  VertZ_AD_V0->GetXaxis()->SetTitle("fVertexZ");
  f2Tracks->Draw("fVertexZ>>VertZ_AD_V0", cut10 + cut11 + cut20);
  VertZ_AD_V0->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // fVertex for Triggers[0] or Triggers[1] or Triggers[2] 
  TH1F *VertZ_Trigg_012 = new TH1F("VertZ_Trigg_012","fVertexZ for Triggers[0] or Triggers[1] or Triggers[2]", 100, -15, 15);
  VertZ_Trigg_012->GetXaxis()->SetTitle("fVertexZ");
  f2Tracks->Draw("fVertexZ>>VertZ_Trigg_012", cut1 + cut20);
  VertZ_Trigg_012->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  //fVertex for Triggers[3] or Triggers[4] and Triggers[7]
  TH1F *VertZ_Trigg_347 = new TH1F("VertZ_Trigg_347","fVertexZ for Triggers[3] or Triggers[4] and Triggers[7]", 100, -15, 15);
  VertZ_Trigg_347->GetXaxis()->SetTitle("fVertexZ");
  f2Tracks->Draw("fVertexZ>>VertZ_Trigg_347", cut2 + cut20);
  VertZ_Trigg_347->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  
  //fVertex for Triggers[8] and Triggers[5] or Triggers[6]
  TH1F *VertZ_Trigg_856 = new TH1F("VertZ_Trigg_856","fVertexZ for Triggers[8] and Triggers[5] or Triggers[6]", 100, -15, 15);
  VertZ_Trigg_856->GetXaxis()->SetTitle("fVertexZ");
  f2Tracks->Draw("fVertexZ>>VertZ_Trigg_856", cut3 + cut20);
  VertZ_Trigg_856->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();


  /*-------------------------------------------*/
  //Track charge
  /*-------------------------------------------*/
  // Track charge without selections 
  TH1F *PairCharge = new TH1F("PairCharge", "PairCharge", 100, -4., 4.);
  PairCharge->GetXaxis()->SetTitle("Q1*Q2(e^2)");
  f2Tracks->Draw("fSign>>PairCharge", cut20);
  PairCharge->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // Track charge with selection abs(fVertexZ)<10
  TH1F *PairCharge_VertZ = new TH1F("PairCharge_VertZ", "PairCharge with VertexZ selection", 100, -4., 4.);
  PairCharge_VertZ->GetXaxis()->SetTitle("Q1*Q2(e^2)");
  f2Tracks->Draw("fSign>>PairCharge_VertZ", cut12 + cut20);
  PairCharge_VertZ->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // Track charge with selection abs(fVertexZ)<10 AD veto V0 veto 
  TH1F *PairCharge_VertZ_ADV0 = new TH1F("PairCharge_VertZ_ADV0", "PairCharge with VertZ and AD V0 selections", 100, -4., 4.);
  PairCharge_VertZ_ADV0->GetXaxis()->SetTitle("Q1*Q2(e^2)");
  f2Tracks->Draw("fSign>>PairCharge_VertZ_ADV0", cut12 + cut10 + cut11 + cut20);
  PairCharge_VertZ_ADV0->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // Track charge with selection abs(fVertexZ)<10 AD veto V0 veto 0n0n
  TH1F *PairCharge_VertZ_ADV0_0n0n = new TH1F("PairCharge_VertZ_ADV0_0n0n", "PairCharge with VertZ AD V0 and 0n0n selections", 100, -4., 4.);
  PairCharge_VertZ_ADV0_0n0n->GetXaxis()->SetTitle("Q1*Q2(e^2)");
  f2Tracks->Draw("fSign>>PairCharge_VertZ_ADV0_0n0n", cut4 + cut7 + cut12 + cut10 + cut11 + cut20);
  PairCharge_VertZ_ADV0_0n0n->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // Track charge with selection abs(fVertexZ)<10 AD veto V0 veto 1n0n 
  TH1F *PairCharge_VertZ_ADV0_1n0n = new TH1F("PairCharge_VertZ_ADV0_1n0n", "PairCharge with VertZ AD V0 and 1n0n selections", 100, -4., 4.);
  PairCharge_VertZ_ADV0_1n0n->GetXaxis()->SetTitle("Q1*Q2(e^2)");
  f2Tracks->Draw("fSign>>PairCharge_VertZ_ADV0_1n0n", cut5 + cut8 + cut10 + cut11 + cut12 + cut20);
  PairCharge_VertZ_ADV0_1n0n->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // Track charge with selection abs(fVertexZ)<10 AD veto V0 veto 0n1n 
  TH1F *PairCharge_VertZ_ADV0_0n1n = new TH1F("PairCharge_VertZ_ADV0_0n1n", "PairCharge with VertZ AD V0 and 0n1n selections", 100, -4., 4.);
  PairCharge_VertZ_ADV0_0n1n->GetXaxis()->SetTitle("Q1*Q2(e^2)");
  f2Tracks->Draw("fSign>>PairCharge_VertZ_ADV0_0n1n", cut6 + cut9 + cut10 + cut11 + cut12 + cut20);
  PairCharge_VertZ_ADV0_0n1n->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  
  /*------------------------------------------ */
  // Phi VS Eta
  /*-------------------------------------------*/
  // fPhiDaughter VS fEtaDaughter without selections
  TH2F *PhiEta = new TH2F("PhiEta", "Phi_VS_Eta without selections", 100, 0., 7., 100, -1.5, 1.5);
  PhiEta->GetXaxis()->SetTitle("Phi");
  PhiEta->GetYaxis()->SetTitle("Eta");
  f2Tracks->Draw("fEtaDaughter:fPhiDaughter>>PhiEta");  
  gPad->SetLogz(1);
  PhiEta->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // fPhiDaughter VS fEtaDaughter with VertexZ AD and V0 selections 
  TH2F *PhiEta_VertZ_ADV0 = new TH2F("PhiEta_VertZ_ADV0", "Phi_VS_Eta with VertexZ AD and V0 selections", 100, 0., 7., 100, -1.5, 1.5);
  PhiEta_VertZ_ADV0->GetXaxis()->SetTitle("Phi");
  PhiEta_VertZ_ADV0->GetYaxis()->SetTitle("Eta");
  f2Tracks->Draw("fEtaDaughter:fPhiDaughter>>PhiEta_VertZ_ADV0", cut10 + cut11 + cut12);
  gPad->SetLogz(1);
  PhiEta_VertZ_ADV0->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // fPhiDaughter VS fEtaDaughter with VertexZ AD V0 and 0n0n selections 
  TH2F *PhiEta_VertZ_ADV0_0n0n = new TH2F("PhiEta_VertZ_ADV0_0n0n", "Phi_VS_Eta with VertexZ AD V0 and 0n0n selections", 100, 0., 7., 100, -1.5, 1.5);
  PhiEta_VertZ_ADV0_0n0n->GetXaxis()->SetTitle("Phi");
  PhiEta_VertZ_ADV0_0n0n->GetYaxis()->SetTitle("Eta");
  f2Tracks->Draw("fEtaDaughter:fPhiDaughter>>PhiEta_VertZ_ADV0_0n0n", cut4 + cut7 + cut10 + cut11 +cut12);
  gPad->SetLogz(1);
  PhiEta_VertZ_ADV0_0n0n->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // fPhiDaughter VS fEtaDaughter with VertexZ AD V0 and 1n0n selections 
  TH2F *PhiEta_VertZ_ADV0_1n0n = new TH2F("PhiEta_VertZ_ADV0_1n0n", "Phi_VS_Eta with VertexZ AD V0 and 1n0n selections", 100, 0., 7., 100, -1.5, 1.5);
  PhiEta_VertZ_ADV0_1n0n->GetXaxis()->SetTitle("Phi");
  PhiEta_VertZ_ADV0_1n0n->GetYaxis()->SetTitle("Eta");
  f2Tracks->Draw("fEtaDaughter:fPhiDaughter>>PhiEta_VertZ_ADV0_1n0n", cut5 + cut8 + cut10 + cut11 + cut12);
  gPad->SetLogz(1);
  PhiEta_VertZ_ADV0_1n0n->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // fPhiDaughter VS fEtaDaughter with VertexZ AD V0 and 0n1n selections 
  TH2F *PhiEta_VertZ_ADV0_0n1n = new TH2F("PhiEta_VertZ_ADV0_0n1n", "Phi_VS_Eta with VertexZ AD V0 and 0n1n selections", 100, 0., 7., 100, -1.5, 1.5);
  PhiEta_VertZ_ADV0_0n1n->GetXaxis()->SetTitle("Phi");
  PhiEta_VertZ_ADV0_0n1n->GetYaxis()->SetTitle("Eta");
  f2Tracks->Draw("fEtaDaughter:fPhiDaughter>>PhiEta_VertZ_ADV0_0n1n", cut6 + cut9 + cut10 + cut11 + cut12);
  gPad->SetLogz(1);
  PhiEta_VertZ_ADV0_0n1n->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  /*------------------------------------------ */
  // Number of TOF tracks (I have to combine Triggers 347 and 856 with other selections !!!!)
  /*-------------------------------------------*/  
  // Number of TOF tracks trigger class without selections
  TH1F *TOFtracks = new TH1F("TOFtracks", "TOFtracks", 100, 0., 4.);
  TOFtracks->GetXaxis()->SetTitle("NTOFtracks");
  f2Tracks->Draw("fNGoodTracksTOF>>TOFtracks", cut20);
  gPad->SetLogy(1);
  TOFtracks->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // Number of TOF tracks trigger012 class 
  TH1F *TOFtracks_Trig012 = new TH1F("TOFtracks_Trig012", "TOFtracks with Triggers[0], [1] and [2] selection", 100, 0., 4.);
  TOFtracks_Trig012->GetXaxis()->SetTitle("NTOFtracks");
  f2Tracks->Draw("fNGoodTracksTOF>>TOFtracks_Trig012", cut1 + cut20);
  gPad->SetLogy(1);
  TOFtracks_Trig012->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // Number of TOF tracks trigger347 class
  TH1F *TOFtracks_Trig347 = new TH1F("TOFtracks_Trig347", "TOFtracks with Triggers[3], [4] and [7] selection", 100, 0., 4.);
  TOFtracks_Trig347->GetXaxis()->SetTitle("NTOFtracks");
  f2Tracks->Draw("fNGoodTracksTOF>>TOFtracks_Trig347", cut1 + cut20);
  gPad->SetLogy(1);
  TOFtracks_Trig347->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // Number of TOF tracks trigger856
  TH1F *TOFtracks_Trig856 = new TH1F("TOFtracks_Trig856", "TOFtracks with Triggers[8], [5] and [6] selection", 100, 0., 4.);
  TOFtracks_Trig856->GetXaxis()->SetTitle("NTOFtracks");
  f2Tracks->Draw("fNGoodTracksTOF>>TOFtracks_Trig856", cut1 + cut20);
  gPad->SetLogy(1);
  TOFtracks_Trig856->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // Number of TOF tracks trigger class with abs(fVertexZ) AD and V0 selections  
  TH1F *TOFtracks_VertZ_ADV0 = new TH1F("TOFtracks_VertZ_ADV0", "TOFtracks with Triggers012 VertexZ AD and V0 selections", 100, 0., 4.);
  TOFtracks_VertZ_ADV0->GetXaxis()->SetTitle("NTOFtracks");
  f2Tracks->Draw("fNGoodTracksTOF>>TOFtracks_VertZ_ADV0", cut1 + cut10 + cut11 + cut12 + cut20);
  gPad->SetLogy(1);
  TOFtracks_VertZ_ADV0->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // Number of TOF tracks trigger class with Triggers012 0n0n abs(fVertexZ) AD and V0 selections
  TH1F *TOFtracks_VertZ_ADV0_0n0n = new TH1F("TOFtracks_VertZ_ADV0_0n0n", "TOFtracks withTriggers012 0n0n VertexZ AD and V0 selections", 100, 0., 4.);
  TOFtracks_VertZ_ADV0_0n0n->GetXaxis()->SetTitle("NTOFtracks");
  f2Tracks->Draw("fNGoodTracksTOF>>TOFtracks_VertZ_ADV0_0n0n", cut1 + cut4 + cut7  + cut10 + cut11 + cut12 + cut20);
  gPad->SetLogy(1);
  TOFtracks_VertZ_ADV0_0n0n->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // Number of TOF tracks trigger class with Triggers012 1n0n abs(fVertexZ) AD and V0 selections 
  TH1F *TOFtracks_VertZ_ADV0_1n0n = new TH1F("TOFtracks_VertZ_ADV0_1n0n", "TOFtracks with Triggers012 1n0n VertexZ AD and V0 selections", 100, 0., 4.);
  TOFtracks_VertZ_ADV0_1n0n->GetXaxis()->SetTitle("NTOFtracks");
  f2Tracks->Draw("fNGoodTracksTOF>>TOFtracks_VertZ_ADV0_1n0n", cut1 + cut5 + cut8  + cut10 + cut11 + cut12 + cut20);
  gPad->SetLogy(1);
  TOFtracks_VertZ_ADV0_1n0n->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear(); 

  // Number of TOF tracks trigger class with Triggers012 0n1n abs(fVertexZ) AD and V0 selections 
  TH1F *TOFtracks_VertZ_ADV0_0n1n = new TH1F("TOFtracks_VertZ_ADV0_0n1n", "TOFtracks with Triggers012 0n1n VertexZ AD and V0 selections", 100, 0., 4.);
  TOFtracks_VertZ_ADV0_0n1n->GetXaxis()->SetTitle("NTOFtracks");
  f2Tracks->Draw("fNGoodTracksTOF>>TOFtracks_VertZ_ADV0_0n1n", cut1 + cut6 + cut9  + cut10 + cut11 + cut12 + cut20);
  gPad->SetLogy(1);
  TOFtracks_VertZ_ADV0_0n1n->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // Number of TOF tracks trigger class with selections
  /*TH1F *TOFtracks_Selections = new TH1F("TOFtracks_Selections", "TOFtracks_Selections", 100, 0., 4.);
  TOFtracks_Selections->GetXaxis()->SetTitle("TOFtracks_Selections");
  f2Tracks->Draw("fNGoodTracksTOF>>TOFtracks_Selections", cut13 + cut14);*/
  

  /*------------------------------------------ */
  // Largest vs smalest pT of the track  
  /*-------------------------------------------*/
  // Largest vs smalest pT of the track for Triggers[0], Triggers[1] and
  // Triggers[2] without selections
  TH2F *PtTrak2D_012 = new TH2F("PtTrak2D_012","PtTrak2D_012", 100, 0., 5., 100, 0., 5.);
  PtTrak2D_012->GetXaxis()->SetTitle("PT1(GeV/c)");
  PtTrak2D_012->GetYaxis()->SetTitle("PT0(GeV/c)");
  f2Tracks->Draw("fPtDaughter:fPt>>PtTrak2D_012", cut1 + cut20);
  gPad->SetLogy(0);
  PtTrak2D_012->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // Largest vs smalest pT of the track for Triggers[3], Triggers[4] and
  // Triggers[7] without selections 
  TH2F *PtTrak2D_347 = new TH2F("PtTrak2D_347","PtTrak2D_347", 100, 0., 5., 100, 0., 5.);
  PtTrak2D_347->GetXaxis()->SetTitle("PT1(GeV/c)");
  PtTrak2D_347->GetYaxis()->SetTitle("PT0(GeV/c)");
  f2Tracks->Draw("fPtDaughter:fPt>>PtTrak2D_347", cut2 + cut20);
  PtTrak2D_347->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // Largest vs smalest pT of the track for Triggers[8], Triggers[5] and
  // Triggers[6] without selections 
  TH2F *PtTrak2D_856 = new TH2F("PtTrak2D_856","PtTrak2D_856", 100, 0., 5., 100, 0., 5.);
  PtTrak2D_856->GetXaxis()->SetTitle("PT1(GeV/c)");
  PtTrak2D_856->GetYaxis()->SetTitle("PT0(GeV/c)");
  f2Tracks->Draw("fPtDaughter:fPt>>PtTrak2D_856", cut3 + cut20);
  PtTrak2D_856->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // Largest vs smalest pT of the track for Triggers[0], Triggers[1] and
  // Triggers[2] with selections1
  TH2F *PtTrak2D_Selections1 = new TH2F("PtTrak2D_Selections1","PtTrak2D_Selections1", 100, 0., 5., 100, 0., 5.);
  PtTrak2D_Selections1->GetXaxis()->SetTitle("PT1(GeV/c)");
  PtTrak2D_Selections1->GetYaxis()->SetTitle("PT0(GeV/c)");
  f2Tracks->Draw("fPtDaughter:fPt>>PtTrak2D_Selections1", cut1 + cut4 + cut7 + cut10 + cut11 + cut12 + cut20);
  PtTrak2D_Selections1->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // Largest vs smalest pT of the track for Triggers[3], Triggers[4] and
  // Triggers[7] with selections2 
  TH2F *PtTrak2D_Selections2 = new TH2F("PtTrak2D_Selections2","PtTrak2D_Selections2", 100, 0., 5., 100, 0., 5.);
  PtTrak2D_Selections2->GetXaxis()->SetTitle("PT1(GeV/c)");
  PtTrak2D_Selections2->GetYaxis()->SetTitle("PT0(GeV/c)");
  f2Tracks->Draw("fPtDaughter:fPt>>PtTrak2D_Selections2", cut2 + cut5 + cut8 + cut10 + cut11 + cut12 + cut20);
  PtTrak2D_Selections2->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // Largest vs smalest pT of the track for Triggers[3], Triggers[4] and
  // Triggers[7] with selections3
  TH2F *PtTrak2D_Selections3 = new TH2F("PtTrak2D_Selections3","PtTrak2D_Selections3", 100, 0., 5., 100, 0., 5.);
  PtTrak2D_Selections3->GetXaxis()->SetTitle("PT1(GeV/c)");
  PtTrak2D_Selections3->GetYaxis()->SetTitle("PT0(GeV/c)");
  f2Tracks->Draw("fPtDaughter:fPt>>PtTrak2D_Selections3", cut12 + cut6 + cut9 + cut10 + cut11 + cut12 + cut20);  
  PtTrak2D_Selections3->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  

  /*-------------------------------------------*/
  // Mass invariant  
  /*-------------------------------------------*/
  // Mass invariant with no cut
  TH1F *Mass_Inv = new TH1F("Mass_Inv", "Mass_Inv",100, 0., 10.);
  Mass_Inv->GetXaxis()->SetTitle("Mass_Inv");
  f2Tracks->Draw("fM>>Mass_Inv", cut20);
  Mass_Inv->Draw("colz");
  gPad->SetLogy(1);
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // Mass invariant with all selections
  TH1F *Mass_Inv_Selections = new TH1F("Mass_Inv_Selections", "Mass_Inv_Selections",100, 0., 10.);
  Mass_Inv_Selections->GetXaxis()->SetTitle("Mass_Inv");
  f2Tracks->Draw("fM>>Mass_Inv_Selections", cut10 + cut11 + cut12 + cut20);  
  Mass_Inv_Selections->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  /*-------------------------------------------*/
  // pT pair
  /*-------------------------------------------*/
  // Pt without selection
  TH1F *Pt = new TH1F("Pt","Pt", 100, 0., 25.);
  Pt->GetXaxis()->SetTitle("Pt");
  f2Tracks->Draw("fPt>>Pt", cut20);
  Pt->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // pT pair for same charge
  TH1F *Pt_same_charge = new TH1F("Pt_same_charge","Pt_same_charge", 100, 0., 25.);
  Pt_same_charge->GetXaxis()->SetTitle("Pt_same_charge");  
  f2Tracks->Draw("fPt>>Pt_same_charge", cut13 + cut20);
  Pt_same_charge->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // pT pair for different charge
  TH1F *Pt_dif_charge = new TH1F("Pt_dif_charge","Pt_dif_charge", 100, 0., 25.);
  Pt_dif_charge->GetXaxis()->SetTitle("Pt_dif_charge");
  f2Tracks->Draw("fPt>>Pt_dif_charge", cut14 + cut20);
  Pt_dif_charge->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // pT pair for invariant mass
  TH1F *Pt_inv_mass = new TH1F("Pt_inv_mass","Pt_inv_mass", 100, 0., 25.);
  Pt_inv_mass->GetXaxis()->SetTitle("Pt_inv_mass");
  f2Tracks->Draw("fPt>>Pt_inv_mass", cut15 + cut20);
  Pt_inv_mass->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  

  /*-------------------------------------------*/
  // Mass Invariant VS Pt/PtDaughter 
  /*-------------------------------------------*/
  // Mass Invariant VS Pt with no selection  
  TH2F *Mass_Pt = new TH2F("Mass_Pt","Invariant Mass VS momentum Pt", 100, 0., 15., 100, 0., 15.);
  Mass_Pt->GetXaxis()->SetTitle("Pt");
  Mass_Pt->GetYaxis()->SetTitle("Mass");
  f2Tracks->Draw("fM:fPt>>Mass_Pt", cut20);
  Mass_Pt->Draw("colz");
  gPad->SetLogy(0);
  gPad->SetLogz(1);
  c.SaveAs("plots.pdf");
  c.Clear();

  // Mass Invariant VS PtDaughter with no selection
  TH2F *Mass_PtDaughter = new TH2F("Mass_PtDaughter","Invariant Mass VS momentum PtDaughter", 100, 0., 2.5, 100, 0., 4.5);
  Mass_PtDaughter->GetXaxis()->SetTitle("PtDaughter");
  Mass_PtDaughter->GetYaxis()->SetTitle("Mass");
  f2Tracks->Draw("fM:fPtDaughter>>Mass_PtDaughter", cut20);
  Mass_PtDaughter->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();


  // PtDaughter with rho condition 
  TH1F *PtDaughter = new TH1F("PtDaughter","PtDaughter without any condition", 100, 0., 2.5);
  PtDaughter->GetXaxis()->SetTitle("PtDaughter");
  f2Tracks->Draw("fPtDaughter>>PtDaughter", cut20);
  PtDaughter->Draw("colz");
  gPad->SetLogy(1);
  c.SaveAs("plots.pdf");
  c.Clear();  
  
  // PtDaughter with rho condition
  TH1F *PtDaughter_rho = new TH1F("PtDaughter_rho","PtDaughter with rho condition", 100, 0., 2.5);
  PtDaughter_rho->GetXaxis()->SetTitle("PtDaughter");
  f2Tracks->Draw("fPtDaughter>>PtDaughter_rho", "fM>0.6 && fM<0.9" + cut20);   
  PtDaughter_rho->Draw("colz");
  gPad->SetLogy(1);  
  c.SaveAs("plots.pdf");
  c.Clear();

  // PtDaughter with jpsi condition 
  TH1F *PtDaughter_jpsi = new TH1F("PtDaughter_jpsi","PtDaughter with jpsi condition", 100, 0., 2.5);
  PtDaughter_jpsi->GetXaxis()->SetTitle("PtDaughter");
  f2Tracks->Draw("fPtDaughter>>PtDaughter_jpsi", "fM>2.9 && fM<3.2" + cut20); 
  PtDaughter_jpsi->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // PtDaughter with rho selection 
  TH2F *PtDaughter_rho_selection = new TH2F("PtDaughter_rho_selection","PtDaughter with rho selection",100, 0., 2.5, 100, 0., 4.5);
  PtDaughter_rho_selection->GetXaxis()->SetTitle("PtDaughter");
  PtDaughter_rho_selection->GetYaxis()->SetTitle("Mass_rho");  
  f2Tracks->Draw("fM:fPtDaughter>>PtDaughter_rho_selection", cut1 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "fM < 1.6 && fM > 0.2");
  PtDaughter_rho_selection->Draw("colz");
  gPad->SetLogy(0);
  c.SaveAs("plots.pdf");
  c.Clear();

  // PtDaughter with jpsi selection
  TH2F *PtDaughter_jpsi_selection = new TH2F("PtDaughter_jpsi_selection","PtDaughter with jpsi selection", 100, 0, 2.5, 100, 0., 4.5);
  PtDaughter_jpsi_selection->GetXaxis()->SetTitle("PtDaughter");
  PtDaughter_jpsi_selection->GetYaxis()->SetTitle("Mass_jpsi");  
  f2Tracks->Draw("fM:fPtDaughter>>PtDaughter_jpsi_selection",  cut1 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "fM > 2.8 && fM < 3.4");
  PtDaughter_jpsi_selection->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  
  /*-------------------------------------------*/
  // nsigTPC
  /*-------------------------------------------*/  
  // nsigTPCPion
  TH1F *nsigTPCPion = new TH1F("nsigTPCPion","nsigTPCPion without selections", 100, -5., 15);
  nsigTPCPion->GetXaxis()->SetTitle("nsigTPCPion");
  f2Tracks->Draw("fnsigTPCPion>>nsigTPCPion", cut20);
  nsigTPCPion->Draw("colz");
  gPad->SetLogy(1);  
  c.SaveAs("plots.pdf");
  c.Clear();

  // nsigTPCKaon   
  TH1F *nsigTPCKaon = new TH1F("nsigTPCKaon","nsigTPCKaon without selections", 100, -20., 20);
  nsigTPCKaon->GetXaxis()->SetTitle("nsigTPCKaon");
  f2Tracks->Draw("fnsigTPCKaon>>nsigTPCKaon", cut20);
  nsigTPCKaon->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // nsigTPCProton   
  TH1F *nsigTPCProton = new TH1F("nsigTPCProton","nsigTPCProton without selections", 100, -22., 10);
  nsigTPCProton->GetXaxis()->SetTitle("nsigTPCProton");
  f2Tracks->Draw("fnsigTPCProton>>nsigTPCProton", cut20);
  nsigTPCProton->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // nsigTPCElectron 
  TH1F *nsigTPCElectron = new TH1F("nsigTPCElectron","nsigTPCElectron without selections", 100, -10., 8.);
  nsigTPCElectron->GetXaxis()->SetTitle("nsigTPCElectron");
  f2Tracks->Draw("fnsigTPCElectron>>nsigTPCElectron", cut20);
  nsigTPCElectron->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // nsigTPCMuon 
  TH1F *nsigTPCMuon = new TH1F("nsigTPCMuon","nsigTPCMuon without selections", 100, -5., 15.);
  nsigTPCMuon->GetXaxis()->SetTitle("nsigTPCMuon");
  f2Tracks->Draw("fnsigTPCMuon>>nsigTPCMuon", cut20);
  nsigTPCMuon->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // nsigTPCElectron VS nsigTPCKaon without selections
  TH2F *nsigTPCEKaon = new TH2F("nsigTPCEKaon","nsigTPCEKaon without selections", 100, -20., 15., 100, -10.,20.);
  nsigTPCEKaon->GetXaxis()->SetTitle("nsigTPCKaon");
  nsigTPCEKaon->GetYaxis()->SetTitle("nsigTPCElectron");
  f2Tracks->Draw("fnsigTPCElectron:fnsigTPCKaon>>nsigTPCEKaon", cut20);
  nsigTPCEKaon->Draw("colz");
  gPad->SetLogz(0);
  gPad->SetLogy(0);
  c.SaveAs("plots.pdf");
  c.Clear();

  // nsigTPCElectron VS nsigTPCKaon with selections
  TH2F *nsigTPCEKaon_Trig012_cuts = new TH2F("nsigTPCEKaon_Trig012_cuts","nsigTPCEKaon_Trig012 with selections", 100, -20., 15., 100, -10.,20.);
  nsigTPCEKaon_Trig012_cuts->GetXaxis()->SetTitle("nsigTPCKaon");
  nsigTPCEKaon_Trig012_cuts->GetYaxis()->SetTitle("nsigTPCElectron");
  f2Tracks->Draw("fnsigTPCElectron:fnsigTPCKaon>>nsigTPCEKaon_Trig012_cuts", cut1 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14+ cut20 + "abs(fnsigTPCPion) > 3");
  nsigTPCEKaon_Trig012_cuts->Draw("colz");
  gPad->SetLogz(0);
  gPad->SetLogy(0);
  c.SaveAs("plots.pdf");
  c.Clear();  

  // nsigTPCElectron VS nsigTPCKaon with selections
  TH2F *nsigTPCEKaon_Trig347_cuts = new TH2F("nsigTPCEKaon_Trig347_cuts","nsigTPCEKaon_Trig347 with selections", 100, -20., 15., 100, -10.,20.);
  nsigTPCEKaon_Trig347_cuts->GetXaxis()->SetTitle("nsigTPCKaon");
  nsigTPCEKaon_Trig347_cuts->GetYaxis()->SetTitle("nsigTPCElectron");
  f2Tracks->Draw("fnsigTPCElectron:fnsigTPCKaon>>nsigTPCEKaon_Trig347_cuts", cut2 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "abs(fnsigTPCPion) > 3");
  nsigTPCEKaon_Trig347_cuts->Draw("colz");
  gPad->SetLogz(0);
  gPad->SetLogy(0);
  c.SaveAs("plots.pdf");
  c.Clear();  

  // nsigTPCElectron VS nsigTPCKaon with selections
  TH2F *nsigTPCEKaon_Trig856_cuts = new TH2F("nsigTPCEKaon_Trig856_cuts","nsigTPCEKaon_Trig856 with selections", 100, -20., 15., 100, -10.,20.);
  nsigTPCEKaon_Trig856_cuts->GetXaxis()->SetTitle("nsigTPCKaon");
  nsigTPCEKaon_Trig856_cuts->GetYaxis()->SetTitle("nsigTPCElectron");
  f2Tracks->Draw("fnsigTPCElectron:fnsigTPCKaon>>nsigTPCEKaon_Trig856_cuts", cut3 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "abs(fnsigTPCPion) > 3");
  nsigTPCEKaon_Trig856_cuts->Draw("colz");
  gPad->SetLogz(0);
  gPad->SetLogy(0);
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // nsigTPCPi VS nsigTPCKaon without selections
  TH2F *nsigTPCPiKaon = new TH2F("nsigTPCPiKaon","nsigTPCPiKaon without selections", 100, -20., 15., 100, -10.,20.);
  nsigTPCPiKaon->GetXaxis()->SetTitle("nsigTPCKaon");
  nsigTPCPiKaon->GetYaxis()->SetTitle("nsigTPCPi");
  f2Tracks->Draw("fnsigTPCPion:fnsigTPCKaon>>nsigTPCPiKaon", cut20);
  nsigTPCPiKaon->Draw("colz");
  gPad->SetLogz(0);
  gPad->SetLogy(0);
  c.SaveAs("plots.pdf");
  c.Clear();

  
  // nsigTPCPi VS nsigTPCKaon with Triggers012 and selections 
  TH2F *nsigTPCPiKaon_Trig012_cuts = new TH2F("nsigTPCPiKaon_Trig012_cuts","nsigTPCPiKaon_Trig012 with selections", 100, -20., 15., 100, -10., 20.);
  nsigTPCPiKaon_Trig012_cuts->GetXaxis()->SetTitle("nsigTPCKaon");
  nsigTPCPiKaon_Trig012_cuts->GetYaxis()->SetTitle("nsigTPCPi");
  f2Tracks->Draw("fnsigTPCPion:fnsigTPCKaon>>nsigTPCPiKaon_Trig012_cuts", cut1 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "abs(fnsigTPCPion) > 3");
  nsigTPCPiKaon_Trig012_cuts->Draw("colz");
  gPad->SetLogz(0);
  gPad->SetLogy(0);  
  c.SaveAs("plots.pdf");
  c.Clear();

  // nsigTPCPi VS nsigTPCKaon with Triggers347 and selections 
  TH2F *nsigTPCPiKaon_Trig347_cuts = new TH2F("nsigTPCPiKaon_Trig347_cuts","nsigTPCPiKaon_Trig347 with selections", 100, -20., 15., 100, -10., 20.);
  nsigTPCPiKaon_Trig347_cuts->GetXaxis()->SetTitle("nsigTPCKaon");
  nsigTPCPiKaon_Trig347_cuts->GetYaxis()->SetTitle("nsigTPCPi");
  f2Tracks->Draw("fnsigTPCPion:fnsigTPCKaon>>nsigTPCPiKaon_Trig347_cuts", cut2 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "abs(fnsigTPCPion) > 3");
  nsigTPCPiKaon_Trig347_cuts->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // nsigTPCPi VS nsigTPCKaon with Triggers347 and selections 
  TH2F *nsigTPCPiKaon_Trig856_cuts = new TH2F("nsigTPCPiKaon_Trig856_cuts","nsigTPCPiKaon_Trig856 with selections", 100, -20., 15., 100, -10., 20.);
  nsigTPCPiKaon_Trig856_cuts->GetXaxis()->SetTitle("nsigTPCKaon");
  nsigTPCPiKaon_Trig856_cuts->GetYaxis()->SetTitle("nsigTPCPi");
  f2Tracks->Draw("fnsigTPCPion:fnsigTPCKaon>>nsigTPCPiKaon_Trig856_cuts", cut3 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "abs(fnsigTPCPion) > 3");
  nsigTPCPiKaon_Trig856_cuts->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // nsigTPCElectron VS nsigTPCMuon without selections
  TH2F *nsigTPCMuE = new TH2F("nsigTPCMuE","nsigTPCMuE without selections", 100, -8., 8., 100, -6., 20.);
  nsigTPCMuE->GetXaxis()->SetTitle("nsigTPCElectron");
  nsigTPCMuE->GetYaxis()->SetTitle("nsigTPCMuon");
  f2Tracks->Draw("fnsigTPCMuon:fnsigTPCElectron>>nsigTPCMuE", cut20);
  nsigTPCMuE->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  
  // nsigTPCElectron VS nsigTPCMuon without selections 
  TH2F *nsigTPCMuE_Trig012 = new TH2F("nsigTPCMuE_Trig012","nsigTPCMuE_012 with selections",  100, -8., 8., 100, -6., 20.);
  nsigTPCMuE_Trig012->GetXaxis()->SetTitle("nsigTPCElectron");
  nsigTPCMuE_Trig012->GetYaxis()->SetTitle("nsigTPCMuon");
  f2Tracks->Draw("fnsigTPCMuon:fnsigTPCElectron>>nsigTPCMuE_Trig012", cut1 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "abs(fnsigTPCMuon) > 3");
  nsigTPCMuE_Trig012->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // nsigTPCElectron VS nsigTPCMuon with selections 
  TH2F *nsigTPCMuE_Trig347 = new TH2F("nsigTPCMuE_Trig347","nsigTPCMuE_Trig347 with selections", 100, -8., 8., 100, -6., 20.);
  nsigTPCMuE_Trig347->GetXaxis()->SetTitle("nsigTPCElectron");
  nsigTPCMuE_Trig347->GetYaxis()->SetTitle("nsigTPCMuon");
  f2Tracks->Draw("fnsigTPCMuon:fnsigTPCElectron>>nsigTPCMuE_Trig347", cut2 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "abs(fnsigTPCMuon) > 3");
  nsigTPCMuE_Trig347->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // nsigTPCElectron VS nsigTPCMuon with selections
  TH2F *nsigTPCMuE_Trig856 = new TH2F("nsigTPCMuE_Trig856","nsigTPCMuE_Trig856 with selections", 100, -8., 8., 100, -6., 20.);
  nsigTPCMuE_Trig856->GetXaxis()->SetTitle("nsigTPCElectron");
  nsigTPCMuE_Trig856->GetYaxis()->SetTitle("nsigTPCMuon");
  f2Tracks->Draw("fnsigTPCMuon:fnsigTPCElectron>>nsigTPCMuE_Trig856", cut3 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "abs(fnsigTPCMuon) > 4");
  nsigTPCMuE_Trig856->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // nsigTPCPi VS nsigTPCProton without selections
  TH2F *nsigTPCPiProton = new TH2F("nsigTPCPiProton","nsigTPCPiProton without selections", 100, -14., 8., 100, -6., 20.);
  nsigTPCPiProton->GetXaxis()->SetTitle("nsigTPCProton");
  nsigTPCPiProton->GetYaxis()->SetTitle("nsigTPCPion");
  f2Tracks->Draw("fnsigTPCPion:fnsigTPCProton>>nsigTPCPiProton", cut20);
  nsigTPCPiProton->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  
  // nsigTPCPi VS nsigTPCProton with selections
  TH2F *nsigTPCPiProton_Trig012 = new TH2F("nsigTPCPiProton_Trig012","nsigTPCPiProton_Trig012 with selections", 100, -14., 8., 100, -6., 20.);
  nsigTPCPiProton_Trig012->GetXaxis()->SetTitle("nsigTPCProton");
  nsigTPCPiProton_Trig012->GetYaxis()->SetTitle("nsigTPCPion");
  f2Tracks->Draw("fnsigTPCPion:fnsigTPCProton>>nsigTPCPiProton_Trig012", cut1 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "abs(fnsigTPCProton) > 3");
  nsigTPCPiProton_Trig012->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();  

  // nsigTPCPi VS nsigTPCProton with selections
  TH2F *nsigTPCPiProton_Trig347 = new TH2F("nsigTPCPiProton_Trig347","nsigTPCPiProton_Trig347 with selections", 100, -14., 8., 100, -6., 20.);
  nsigTPCPiProton_Trig347->GetXaxis()->SetTitle("nsigTPCProton");
  nsigTPCPiProton_Trig347->GetYaxis()->SetTitle("nsigTPCPion");
  f2Tracks->Draw("fnsigTPCPion:fnsigTPCProton>>nsigTPCPiProton_Trig347", cut2 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + "abs(fnsigTPCProton) > 3");
  nsigTPCPiProton_Trig347->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // nsigTPCPi VS nsigTPCProton with selections
  TH2F *nsigTPCPiProton_Trig856 = new TH2F("nsigTPCPiProton_Trig856","nsigTPCPiProton_Trig856 with selections", 100, -14., 8., 100, -6., 20.);
  nsigTPCPiProton_Trig856->GetXaxis()->SetTitle("nsigTPCProton");
  nsigTPCPiProton_Trig856->GetYaxis()->SetTitle("nsigTPCPion");
  f2Tracks->Draw("fnsigTPCPion:fnsigTPCProton>>nsigTPCPiProton_Trig856", cut3 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "abs(fnsigTPCProton) > 3");
  nsigTPCPiProton_Trig856->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // nsigTPCElectron VS nsigTPCProton without selections
  TH2F *nsigTPCElProton = new TH2F("nsigTPCElProton","nsigTPCElProton without selections", 100, -15., 8., 100, -8., 8.);
  nsigTPCElProton->GetXaxis()->SetTitle("nsigTPCProton");
  nsigTPCElProton->GetYaxis()->SetTitle("nsigTPCElectron");
  f2Tracks->Draw("fnsigTPCElectron:fnsigTPCProton>>nsigTPCElProton", cut20);
  nsigTPCElProton->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  
  // nsigTPCElectron VS nsigTPCProton with selections
  TH2F *nsigTPCElProton_Trig012 = new TH2F("nsigTPCElProton_Trig012","nsigTPCElProton_Trig012 with selections", 100, -15., 8., 100, -8., 8.);
  nsigTPCElProton_Trig012->GetXaxis()->SetTitle("nsigTPCProton");
  nsigTPCElProton_Trig012->GetYaxis()->SetTitle("nsigTPCElectron");
  f2Tracks->Draw("fnsigTPCElectron:fnsigTPCProton>>nsigTPCElProton_Trig012", cut1 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "abs(fnsigTPCProton) > 3");
  nsigTPCElProton_Trig012->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();  

  // nsigTPCElectron VS nsigTPCProton with selections
  TH2F *nsigTPCElProton_Trig347 = new TH2F("nsigTPCElProton_Trig347","nsigTPCElProton_Trig347 with selections", 100, -15., 8., 100, -8., 8.);
  nsigTPCElProton_Trig347->GetXaxis()->SetTitle("nsigTPCProton");
  nsigTPCElProton_Trig347->GetYaxis()->SetTitle("nsigTPCElectron");
  f2Tracks->Draw("fnsigTPCElectron:fnsigTPCProton>>nsigTPCElProton_Trig347", cut2 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "abs(fnsigTPCProton) > 3");
  nsigTPCElProton_Trig347->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();  

  // nsigTPCPi VS nsigTPCProton with selections
  TH2F *nsigTPCElProton_Trig856 = new TH2F("nsigTPCElProton_Trig856","nsigTPCElProton_Trig856 with selections", 100, -15., 8., 100, -8., 8.);
  nsigTPCElProton_Trig856->GetXaxis()->SetTitle("nsigTPCProton");
  nsigTPCElProton_Trig856->GetYaxis()->SetTitle("nsigTPCElectron");
  f2Tracks->Draw("fnsigTPCElectron:fnsigTPCProton>>nsigTPCElProton_Trig856", cut3 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "abs(fnsigTPCProton) > 3");
  nsigTPCElProton_Trig856->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // nsigTPCMuon VS nsigTPCKaon without selections
  TH2F *nsigTPCMuKaon = new TH2F("nsigTPCMuKaon","nsigTPCMuKaon without selections", 100, -20., 4., 100, -10., 10);
  nsigTPCMuKaon->GetXaxis()->SetTitle("nsigTPCKaon");
  nsigTPCMuKaon->GetYaxis()->SetTitle("nsigTPCMuon");
  f2Tracks->Draw("fnsigTPCMuon:fnsigTPCKaon>>nsigTPCMuKaon", cut20);
  nsigTPCMuKaon->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // nsigTPCMuon VS nsigTPCKaon with selections 
  TH2F *nsigTPCMuKaon_Trig012 = new TH2F("nsigTPCMuKaon_Trig012","nsigTPCMuKaon_Trig012 with selections", 100, -20., 4., 100, -10., 10.);
  nsigTPCMuKaon_Trig012->GetXaxis()->SetTitle("nsigTPCKaon");
  nsigTPCMuKaon_Trig012->GetYaxis()->SetTitle("nsigTPCMuon");
  f2Tracks->Draw("fnsigTPCMuon:fnsigTPCKaon>>nsigTPCMuKaon_Trig012", cut1 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 /*+ "abs(fnsigTPCMuon) > 3"*/);
  nsigTPCMuKaon_Trig012->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // nsigTPCMuon VS nsigTPCKaon with selections 
  TH2F *nsigTPCMuKaon_Trig347 = new TH2F("nsigTPCMuKaon_Trig347","nsigTPCMuKaon_Trig347 with selections", 100, -20., 4., 100, -10., 10.);
  nsigTPCMuKaon_Trig347->GetXaxis()->SetTitle("nsigTPCKaon");
  nsigTPCMuKaon_Trig347->GetYaxis()->SetTitle("nsigTPCMuon");
  f2Tracks->Draw("fnsigTPCMuon:fnsigTPCKaon>>nsigTPCMuKaon_Trig347", cut2 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "abs(fnsigTPCMuon) > 3");
  nsigTPCMuKaon_Trig347->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // nsigTPCMuon VS nsigTPCKaon with selections 
  TH2F *nsigTPCMuKaon_Trig856 = new TH2F("nsigTPCMuKaon_Trig856","nsigTPCMuKaon_Trig856 with selections", 100, -20., 4., 100, -10., 10.);
  nsigTPCMuKaon_Trig856->GetXaxis()->SetTitle("nsigTPCKaon");
  nsigTPCMuKaon_Trig856->GetYaxis()->SetTitle("nsigTPCMuon");
  f2Tracks->Draw("fnsigTPCMuon:fnsigTPCKaon>>nsigTPCMuKaon_Trig856", cut3 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "abs(fnsigTPCMuon) > 3");
  nsigTPCMuKaon_Trig856->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  // nsigTPCMuon VS nsigTPCPion without selections
  TH2F *nsigTPCMuPi = new TH2F("nsigTPCMuPi","nsigTPCMuPi without selections", 100, -4., 20., 100, -6., 20);
  nsigTPCMuPi->GetXaxis()->SetTitle("nsigTPCPion");
  nsigTPCMuPi->GetYaxis()->SetTitle("nsigTPCMuon");
  f2Tracks->Draw("fnsigTPCMuon:fnsigTPCPion>>nsigTPCMuPi", cut20);
  nsigTPCMuPi->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();  

  // nsigTPCMuon VS nsigTPCPion with selections
  TH2F *nsigTPCMuPi_Trig012 = new TH2F("nsigTPCMuPi_Trig012","nsigTPCMuPi_Trig012 with selections", 100, -4., 20., 100, -6., 20.);
  nsigTPCMuPi_Trig012->GetXaxis()->SetTitle("nsigTPCPion");
  nsigTPCMuPi_Trig012->GetYaxis()->SetTitle("nsigTPCMuon");
  f2Tracks->Draw("fnsigTPCMuon:fnsigTPCPion>>nsigTPCMuPi_Trig012", cut1 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "abs(fnsigTPCMuon) > 3");
  nsigTPCMuPi_Trig012->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // nsigTPCMuon VS nsigTPCPion with selections
  TH2F *nsigTPCMuPi_Trig347 = new TH2F("nsigTPCMuPi_Trig347","nsigTPCMuPi_Trig347 with selections", 100, -4., 20., 100, -6., 20.);
  nsigTPCMuPi_Trig347->GetXaxis()->SetTitle("nsigTPCPion");
  nsigTPCMuPi_Trig347->GetYaxis()->SetTitle("nsigTPCMuon");
  f2Tracks->Draw("fnsigTPCMuon:fnsigTPCPion>>nsigTPCMuPi_Trig347", cut2 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "abs(fnsigTPCMuon) > 3");
  nsigTPCMuPi_Trig347->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  // nsigTPCMuon VS nsigTPCPion with selections 
  TH2F *nsigTPCMuPi_Trig856 = new TH2F("nsigTPCMuPi_Trig856","nsigTPCMuPi_Trig856 with selections", 100, -4., 20., 100, -6., 20.);
  nsigTPCMuPi_Trig856->GetXaxis()->SetTitle("nsigTPCPion");
  nsigTPCMuPi_Trig856->GetYaxis()->SetTitle("nsigTPCMuon");
  f2Tracks->Draw("fnsigTPCMuon:fnsigTPCPion>>nsigTPCMuPi_Trig856", cut3 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + cut20 + "abs(fnsigTPCMuon) > 3");
  nsigTPCMuPi_Trig856->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();


  /*-------------------------------------------*/
  // PID: Particle IDentification
  /*-------------------------------------------*/
  // dE/dx VS Pt
  TH2F *dEdx_Pt = new TH2F("dEdx_Pt","dE/dx VS Pt of pion, electron, proton, and Kaon", 100, 0., 5, 100, 40., 140.);
  dEdx_Pt->GetXaxis()->SetTitle("Pt");
  dEdx_Pt->GetYaxis()->SetTitle("dE/dx");
  f2Tracks->Draw("fdEdx:fPtDaughter>>dEdx_Pt", cut3 + cut10 + cut11 + cut12 + "fnsigTPCKaon > 0 &&  fnsigTPCKaon < 3 || fnsigTPCPion > -3 && fnsigTPCPion < 4 && fnsigTPCElectron > -1 && fnsigTPCElectron < 4 || fnsigTPCProton > 3 && fnsigTPCProton < 3 || fnsigTPCMuon > -2 && fnsigTPCMuon < 5");
  gPad->SetLogz(1);  
  dEdx_Pt->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  

  /*-------------------------------------------*/
  // Track12Channel
  /*-------------------------------------------*/
  //Track12Channel without any selection
  TH1F *Track12Channel = new TH1F("Track12Channel","Track12Chanel without selection", 100, 0, 50);
  Track12Channel->GetXaxis()->SetTitle("Track12Channel");
  f2Tracks->Draw("fTrack12Channel>>Track12Channel");
  Track12Channel->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  //Track12Channel with cuts
  TH1F *Track12Channel_Cuts = new TH1F("Track12Channel_Cuts","Track12Chanel with selection", 100, 0, 50);
  Track12Channel_Cuts->GetXaxis()->SetTitle("Track12Channel");
  f2Tracks->Draw("fTrack12Channel>>Track12Channel_Cuts", cut2 + cut4 + cut7 + cut10 + cut11 + cut12 + cut14 + "abs(fnsigTPCProton) > 3 || fnsigTPCKaon < 0 &&  fnsigTPCKaon > 3 || abs(fnsigTPCPion) > 3 || fnsigTPCElectron < -1 && fnsigTPCElectron > 4 || fnsigTPCMuon < -2 && fnsigTPCMuon >5 ");
  Track12Channel_Cuts->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();

  
  /*-------------------------------------------*/
  // nsigTPCKaon and nsigTPCElectron with veto
  /*-------------------------------------------*/
  // nsigTPCKaon with veto    
  TH1F *nsigTPCKaon_veto = new TH1F("nsigTPCKaon_veto","nsigTPCKaon after veto", 100, -20., 20);
  nsigTPCKaon_veto->GetXaxis()->SetTitle("nsigTPCKaon");
  f2Tracks->Draw("fnsigTPCKaon>>nsigTPCKaon_veto", "abs(fnsigTPCProton) > 3 || fnsigTPCKaon < 0 &&  fnsigTPCKaon > 3 || abs(fnsigTPCPion) > 3 || fnsigTPCElectron < -1 && fnsigTPCElectron > 4 || fnsigTPCMuon < -2 && fnsigTPCMuon >5 ");
  nsigTPCKaon_veto->Draw("colz");
  gPad->SetLogy(1);
  c.SaveAs("plots.pdf");
  c.Clear();

  // nsigTPCSElectron with 
  TH1F *nsigTPCElectron_veto = new TH1F("nsigTPCElectron_veto","nsigTPCElectron without selections", 100, -10., 8.);
  nsigTPCElectron_veto->GetXaxis()->SetTitle("nsigTPCElectron");
  f2Tracks->Draw("fnsigTPCElectron>>nsigTPCElectron_veto",  "abs(fnsigTPCProton) > 3 || fnsigTPCKaon < 0 &&  fnsigTPCKaon > 3 || abs(fnsigTPCPion) > 3 || fnsigTPCElectron < -1 && fnsigTPCElectron > 4 || fnsigTPCMuon < -2 && fnsigTPCMuon >5 " + cut1 + cut4 + cut7 + cut10 + cut11 + cut12 + cut20);
  nsigTPCElectron_veto->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();  

  /*-------------------------------------------*/
  // Pt of selected electron
  /*-------------------------------------------*/
  //Pt selected of electron 
  TH1F *Ptofelectrons = new TH1F("Ptofelectrons","Pt of selected electrons", 10, 0., 2.5);
  Ptofelectrons->GetXaxis()->SetTitle("Pt(GeV/c)");
  f2Tracks->Draw("fPtDaughter>>Ptofelectrons", "abs(fnsigTPCKaon) > 5 && abs(fnsigTPCPion) > 3 && abs(fnsigTPCProton) > 3 && abs(fnsigTPCMuon) > 3" + cut1 + cut4 + cut7 + cut10 + cut11 + cut12 + cut20 + "(fnsigTPCElectron > -3 && fnsigTPCElectron < 3)" );
  gPad->SetLogy(0);
  Ptofelectrons->Draw("colz");
  c.SaveAs("plots.pdf");
  c.Clear();
  
  
  c.SaveAs("plots.pdf]");
  

  
  delete ZNA_ZNC;
  delete ZNA_ZNC_0n0n;
  delete ZNA_ZNC_1n0n;
  delete ZNA_ZNC_0n1n;
  delete ZPA_ZPC;
  delete ZPA_ZPC_0n0n;
  delete ZPA_ZPC_1n0n;
  delete ZPA_ZPC_0n1n;
  delete VertZ;
  delete VertZ_0n0n;
  delete VertZ_1n0n;
  delete VertZ_0n1n;
  delete VertZ_AD;
  delete VertZ_V0;
  delete VertZ_AD_V0;
  delete VertZ_Trigg_012;
  delete VertZ_Trigg_347;
  delete VertZ_Trigg_856;
  delete PairCharge;
  delete PairCharge_VertZ;
  delete PairCharge_VertZ_ADV0;
  delete PairCharge_VertZ_ADV0_0n0n;
  delete PairCharge_VertZ_ADV0_1n0n;
  delete PairCharge_VertZ_ADV0_0n1n;
  delete PhiEta;
  delete PhiEta_VertZ_ADV0;
  delete PhiEta_VertZ_ADV0_0n0n;
  delete PhiEta_VertZ_ADV0_1n0n;
  delete PhiEta_VertZ_ADV0_0n1n;
  /*delete VertZ;
  delete VertZ_0n0n;
  delete VertZ_1n0n;
  delete VertZ_0n1n;
  delete VertZ_ADA_ADC;
  delete VertZ_V0A_V0C;
  delete VertZ_ADA_ADC_V0A_V0C;
  delete VertZ_Trigg_012;
  delete VertZ_Trigg_347;
  delete VertZ_Trigg_856;
  delete PhiEta;
  //delete PhiEta_Selections;
  delete TOFtracks;
  delete TOFtracks_VertZ_ADV0;
  delete TOFtracks_Selections;
  delete PtTrak2D_012;
  delete PtTrak2D_Selections1;
  delete PtTrak2D_347;
  delete PtTrak2D_Selections2;
  delete PtTrak2D_856;
  delete PtTrak2D_Selections3;
  delete Pt_same_charge;
  delete Pt_dif_charge;
  delete Pt_inv_mass;
  delete Mass_Inv;
  delete Mass_Inv_Selections;*/
}

