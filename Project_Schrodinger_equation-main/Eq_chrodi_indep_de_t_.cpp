/// This code calculate the energy of the first state and other excited states for a particle in quantum box and give
/// us the wave function, using the Euler-Cromer algorithm.
#include<iostream>
#include <fstream> // flux vers fichier
#include<cmath>
#include<iomanip>

using namespace std;

main()
{
                long double s, phi(1.), dphi(0.), E(0.), h(1), m(1), x(0.) ,dx=0.01, dE=0.001, gamma, A[101], B[101], C[101], somme(0.);
                int j(0);
                string nomFichier1("data1.txt");
                ofstream monFlux1(nomFichier1.c_str());

///Energie of the fundamental state
            for(E=0; E<=1.5;E+=dE)
                {
                phi=1.0;
                dphi=0.0;
                j=0;
                for(float x=0; x<=1; x+=dx)
                {
                gamma=-E*2*phi;
                dphi=dphi+gamma*dx;
                phi=phi+dphi*dx;
                j++;

                if(phi<=0.0)
                {
                  if(x=1){
                  std::cout<<"Energy of the fundamental state is: "<<std::scientific<<E<<std::endl;
                  goto L2;}
                }

                }
                }
L2:
                cout<<"******"<<endl;

/// probability density function of the fundamental state
                phi=1.0;
                dphi=0.0;
                x=0;
                s=0;
            for(int i=0; i<100; i++)
                {
                if(monFlux1)
                {gamma=-2*E*phi;
                dphi=dphi+gamma*dx;
                phi=phi+dphi*dx;
                A[i]=phi; ///it help us to calculate the integral in the end of this exercise
                s=s+phi*phi*dx; ///it help us to normalize the probability density function of the fundamental state
                monFlux1<<setw(8)<<x<<setw(15)<<phi<<endl;
                x=x+dx;
                }
                else
                {cout << "ERREUR: Impossible d’ouvrir le fichier." << endl;
                }
                }
                monFlux1.close();

/// Normalize probability density function of the fundamental state
                string nomFichier7("data7.txt");
                ofstream monFlux7(nomFichier7.c_str());
                phi=1.0;
                dphi=0.0;
                x=0;
            for(int i=0; i<100; i++)
                {
                if(monFlux7)
                {gamma=-2*E*phi;
                dphi=dphi+gamma*dx;
                phi=phi+dphi*dx;
                ///phi=phi/sqrt(s);
                monFlux7<<setw(8)<<x<<setw(15)<<phi/sqrt(s)<<endl;
                x=x+dx;
                }
                else
                {cout << "ERREUR: Impossible d’ouvrir le fichier." << endl;
                }
                }
                monFlux1.close();

/// 1st exited state
            for(E=E; E<=5;E+=dE)
                {
                phi=0.0;
                dphi=1.0;
                x=0;
                for(int i=0; i<=100; i++)
                {
                    gamma=-E*2*phi;
                    dphi=dphi+gamma*dx;
                    phi=phi+dphi*dx;
                    if(phi<=0.0)
                    {
                    if(x=1){
                    std::cout<<"Energy of the 1st excited state is: "<<std::scientific<<E<<std::endl;
                    goto L3;}
                    }
                    x=x+dx;
                }
                }
L3:
                cout<<"******"<<endl;

/// probability density function of the first excited state
                string nomFichier2("data2.txt");
                ofstream monFlux2(nomFichier2.c_str());
                phi=0.0;
                dphi=1.0;
                x=0;
            for(int i=0; i<100; i++)
                {
                if(monFlux2)
                {gamma=-2*E*phi;
                dphi=dphi+gamma*dx;
                phi=phi+dphi*dx;
                monFlux2<<setw(8)<<x<<setw(15)<<phi<<endl;
                x=x+dx;
                }
                else
                {cout << "ERREUR: Impossible d’ouvrir le fichier." << endl;
                }
                }
                monFlux2.close();

/// 2nd exited state
            for(E=E; E<=15;E+=dE)
                {
                phi=1;
                dphi=0.0;
                x=0;
                for(int i=0; i<=100; i++)
                    {
                    gamma=-E*2*phi;
                    dphi=dphi+gamma*dx;
                    phi=phi+dphi*dx;
                    if(phi>=0.0)
                    {
                    if(x>=1){
                    std::cout<<"Energy of the 2st excited state is: "<<std::scientific<<E<<std::endl;
                    goto L4;}
                    }
                    x=x+dx;
                    }
                }
L4:
                cout<<"******"<<endl;

    /// probability density function of the second excited state
                string nomFichier3("data3.txt");
                ofstream monFlux3(nomFichier3.c_str());
                phi=1.0;
                dphi=0.0;
                x=0;
            for(int i=0; i<100; i++)
                {
                if(monFlux2)
                {gamma=-2*E*phi;
                dphi=dphi+gamma*dx;
                phi=phi+dphi*dx;
                monFlux3<<setw(8)<<x<<setw(15)<<phi<<endl;
                x=x+dx;
                }
                else
                {cout << "ERREUR: Impossible d’ouvrir le fichier." << endl;
                }
                }
                monFlux3.close();

///Small perturbation: V0=20
            for(E=0; E<=5;E+=dE)
                {
                phi=1.0;
                dphi=0.0;
                x=0;
                for(int i=0; i<=100; i++)
                {
                    if(x>=0 && x<=0.1)
                    { gamma=-2*(E-20)*phi;
                    }
                    else{
                    gamma=-2*E*phi;
                    }
                dphi=dphi+gamma*dx;
                phi=phi+dphi*dx;
                B[i]=phi;

                if(phi<=0.0 && x>=1)
                {
                std::cout<<"First case: Energy of the fundamental state after perturbation is: "<<std::scientific<<E<<std::endl;
                goto L5;
                }
                x=x+dx;
                }
                }
L5:
                cout<<"******"<<endl;

    /// probability density function of the fundamental state with the perturbation V0
                string nomFichier4("data4.txt");
                ofstream monFlux4(nomFichier4.c_str());
                phi=1.0;
                dphi=0.0;
                x=0;
            for(int i=0; i<100; i++)
                {
                if(monFlux4)
                {
                if(x>=0 && x<=0.1)
                { gamma=-2*(E-20)*phi;
                }
                else{
                gamma=-2*E*phi;
                }
                dphi=dphi+gamma*dx;
                phi=phi+dphi*dx;
                monFlux4<<setw(8)<<x<<setw(15)<<phi<<endl;
                x=x+dx;
                }
                else
                {cout << "ERREUR: Impossible to open the file." << endl;
                }
                }
                monFlux4.close();

///Calcule de l'integrale
            for(int i=0; i<100; i++)
                {somme=somme+A[i]*B[i]*dx;
                }
                cout<<"la valeur de l'integral est "<<somme<<endl;
                cout<<"******"<<endl;


///Small perturbation: V0=10
            for(E=0; E<=15;E+=dE)
                {
                phi=1.0;
                dphi=0.0;
                x=0;
                for(int i=0; i<=100; i++)
                    {
                    if(x>=0 && x<=1)
                    { gamma=-2*(E-10)*phi;
                    }
                    else{
                    gamma=-2*E*phi;
                    }
                    dphi=dphi+gamma*dx;
                    phi=phi+dphi*dx;

                    if(phi<=0.0 && x>=1)
                    {
                    std::cout<<"Second case: Energy of the fundamental state after perturbation is: "<<std::scientific<<E<<std::endl;
                    goto L6;
                    }
                    x=x+dx;
                    }
                }
L6:
                cout<<"******"<<endl;

/// probability density function of the fundamental state with the perturbation V0
                string nomFichier5("data5.txt");
                ofstream monFlux5(nomFichier5.c_str());
                phi=1.0;
                dphi=0.0;
                x=0;
            for(int i=0; i<100; i++)
                {
                if(monFlux5)
                {
                if(x>=0 && x<=0.1)
                { gamma=-2*(E-10)*phi;
                }
                else{
                gamma=-2*E*phi;
                  }
                dphi=dphi+gamma*dx;
                phi=phi+dphi*dx;
                monFlux5<<setw(8)<<x<<setw(15)<<phi<<endl;
                x=x+dx;
                }
                else
                {cout << "ERREUR: Impossible to open the file." << endl;
                }
                }
                monFlux5.close();


///Small perturbation: V0=20
            for(E=0; E<=15;E+=dE)
                {
                phi=1.0;
                dphi=0.0;
                x=0;
                for(int i=0; i<=100; i++)
                    {
                    if(x>=0 && x<=0.05)
                    {gamma=-2*(E-20)*phi;
                    }
                    else{
                    gamma=-2*E*phi;
                    }
                dphi=dphi+gamma*dx;
                phi=phi+dphi*dx;

                if(phi<=0.0 && x>=1)
                {
                std::cout<<"Third case: Energy of the fundamental state after perturbation is: "<<std::scientific<<E<<std::endl;
                goto L7;
                }
                x=x+dx;
                }
                }
L7:
                cout<<"******"<<endl;

/// probability density function of the fundamental state with the perturbation V0
                string nomFichier6("data6.txt");
                ofstream monFlux6(nomFichier6.c_str());
                phi=1.0;
                dphi=0.0;
                x=0;
            for(int i=0; i<100; i++)
                {
                if(monFlux6)
                {
                if(x>=0 && x<=0.1)
                { gamma=-2*(E-20)*phi;
                }
                else{
                gamma=-2*E*phi;
                }
                dphi=dphi+gamma*dx;
                phi=phi+dphi*dx;
                monFlux6<<setw(8)<<x<<setw(15)<<phi<<endl;
                x=x+dx;
                }
                else
                {cout << "ERREUR: Impossible to open the file." << endl;
                }
                }
                monFlux6.close();

}
