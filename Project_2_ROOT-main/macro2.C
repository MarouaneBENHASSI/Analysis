void macro2()
{
TH1F *hUnif = new TH1F("hUnif", "x1",100,10.,20.);
TH1F *h2Unif = new TH1F("h2Unif", "x1x2",100,10.,20.);
TH1F *h10Unif = new TH1F("h10Unif", "moy(x)",100,10.0,20.0);
TFile *input = new TFile("dataNtuple.root", "read");
TTree *MyTree = (TTree*)input->Get("MyTree");
float x1, x2, x3, x4, x5, x6, x7, x8, x9, x10;
MyTree->SetBranchAddress("x1",&x1);
MyTree->SetBranchAddress("x2",&x2);
MyTree->SetBranchAddress("x3",&x3);
MyTree->SetBranchAddress("x4",&x4);
MyTree->SetBranchAddress("x5",&x5);
MyTree->SetBranchAddress("x6",&x6);
MyTree->SetBranchAddress("x7",&x7);
MyTree->SetBranchAddress("x8",&x8);
MyTree->SetBranchAddress("x9",&x9);
MyTree->SetBranchAddress("x10",&x10);
Long64_t entries = MyTree->GetEntries();
for(int i=0; i<entries; i++)
{
MyTree->GetEntry(i);
hUnif->Fill(x1);
h2Unif->Fill((x1+x2)*0.5);
h10Unif->Fill((x1+x2+x3+x4+x5+x6+x7+x8+x9+x10)*0.1); 
}
TCanvas *cH1 = new TCanvas("cH1","multipads",890,890);
cH1->Divide(3,0,0,0);
cH1->cd(1);
hUnif->GetXaxis()->SetTitle("x1");
hUnif->Draw();
cH1->cd(2);
h2Unif->GetXaxis()->SetTitle("(x1+x2)*0.5");
h2Unif->Draw();
cH1->cd(3);
h10Unif->GetXaxis()->SetTitle("moy(x)");
h10Unif->Draw();
TF1 *fit = new TF1("lissage", "gaus", 15., 0.9152);
h10Unif->Fit("lissage");
}
