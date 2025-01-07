void macro1()
{ 
auto gen = new TRandom3();
double x1, x2, x3, x4, x5, x6, x7, x8, x9, x10;
TFile *output = new TFile("dataNtuple.root", "recreate");
TNtuple *MyTree = new TNtuple("MyTree", "MyTree", "x1:x2:x3:x4:x5:x6:x7:x8:x9:x10");
 
for(int i =0; i<100000; i++)
{
x1 = gen->Uniform(10.0,20.0);
x2 = gen->Uniform(10.0,20.0);
x3 = gen->Uniform(10.0,20.0);
x4 = gen->Uniform(10.0,20.0);
x5 = gen->Uniform(10.0,20.0);
x6 = gen->Uniform(10.0,20.0);
x7 = gen->Uniform(10.0,20.0);
x8 = gen->Uniform(10.0,20.0);
x9 = gen->Uniform(10.0,20.0);
x10 = gen->Uniform(10.0,20.0);
      
MyTree->Fill(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10);
}
output->Write();
output->Close();  
}
