/// Solving the Cornell Equation                                  
#include<iostream>
#include<iomanip>
#include<cmath>
#include<fstream>

using namespace std;

main()
{
    float a(1.), c(1.), dx(0.01), gamma(0.), u(0.), du(0.), E(0.), dE=0.001, x(\
0.001);
    int k(0), d(3), l(0) ;

 for(int l=0; l<4; l++)
 {
     cout<<"pour l = "<<l<<endl;
 L0:
    k=d+2*l;
u=0.;
    du=1.;
    ///x=1.;                                                                    
    E=E+dE;
    for(x=0.001; x<=a; x=x+dx)
    {
        gamma=((k-1)*(k-3)/(4*x*x)-a/x+c*x-E)*u;
        du=du+gamma*dx;
        u=u+du*dx;
        ///cout<<"la valeur propre de l'état dondamentale est: "<<u<<endl;      
        if(x>=0.99)
        {
 ///cout<<"j'ai entrer en x"<<endl;                                  
            if(u>0.)
            {
             	cout<<"la valeur propre de l'état dondamentale est: "<<E<<endl;
		goto L1;
            }
            else{goto L0;}
	}
    }
L1:
    k=0;
}
}
