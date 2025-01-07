///
/// Ce code calcule la postion, la vitesse et l'accelération ainsi que l'énergie totale d'un oject (une planète comme la terre)
/// en mouvement orbital (autour du soleil par exemple) en utilisant deux méthodes à savoir celle d'Euler Cromer et celle d'Euler Richardson
///

#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
using namespace std;
int main()
{
    long double vx(0), vy, y(0), x(1), h(0.005), t0(0), r(0), GM(4*acos(-1)*acos(-1)), vmx(0), vmy(0), gamx(0), gamy(0), xm(0), ym(0), E(0), m(5.99e+24);
    long double x1(1),x2(5.21), y1(0), y2(0), vx1(0), vx2(0), vy1(0), vy2(0), r1(0), r2(0), r21(0), GM1(4*acos(-1)*acos(-1)) ,GM2(39.692), Gm1(1.1921e-4), Gm2(0.0376);
    long double vmx1(0), vmy1(0), vmx2(0), vmy2(0), gamx1(0), gamy1(0), gamx2(0), gamy2(0), xm1(0), ym1(0), xm2(0), ym2(0);
/// Question 1, 2 et 3:
                                       ///* Méthode d'Eleur Cromer*/

    //la distance qui sépare les deux objets
    r=sqrt(x*x+y*y);
    vy=sqrt(GM/r);
            // Nom du fichier
        string nomFichier("data.txt");
               //D´eclaration du flux
        ofstream monFlux(nomFichier.c_str());
        cout<<"--- Aplication de la méthode de d'Euler Cromer---"<<endl;
    cout<<"***********************************************************************************************************************"<<endl;
    cout<<setw(8)<<"Temps*"<<setw(15)<<"Abs x*"<<setw(15)<<"Abs y*"<<setw(15)<<"vx*"<<setw(15)<<"vy*"<<setw(15)<<"Gamma x*"<<setw(15)<<"Gamma y*"<<setw(15)<<"Energ tot*"<<endl;
    cout<<"***********************************************************************************************************************"<<endl;
    for(int i=0; i<1000; i++)
    {
        r=sqrt(x*x+y*y);
        vy=vy-y*GM*h/(r*r*r);
        vx=vx-x*GM*h/(r*r*r);
        y=y+vy*h;
        x=x+vx*h;
        t0=t0+h;
        E=0.5*(vx*vx+vy*vy)-GM*m/r;
        if(monFlux)
          {
             monFlux<<setw(8)<<t0<<setw(15)<<x<<setw(15)<<y<<setw(15)<<vx<<setw(15)<<vy<<endl;
             cout<<setw(8)<<t0<<setw(15)<<x<<setw(15)<<y<<setw(15)<<vx<<setw(15)<<vy<<setw(15)<<GM*x/(r*r*r)<<setw(15)<<GM*y/(r*r*r)<<setw(15)<<E<<endl;

          }
        else
          {
             cout << "ERREUR: Impossible d’ouvrir le fichier." << endl;
          }
    }
    monFlux.close();
                                       ///*Méthode d'Euler Richardson*/

                // Nom du fichier
        string nomFichier2("data2.txt");
               //D´eclaration du flux
        ofstream monFlux2(nomFichier2.c_str());
    t0=0; vx=0; y=0; x=1; r=0, E=0;
    //la distance qui sépare les deux objets
    r=sqrt(x*x+y*y);
    vy=sqrt(GM/r);
            cout<<"--- Aplication de la méthode de d'Euler Richardson---"<<endl;
    cout<<"***********************************************************************************************************************"<<endl;
    cout<<setw(8)<<"Temps*"<<setw(15)<<"Abs x*"<<setw(15)<<"Abs y*"<<setw(15)<<"vx*"<<setw(15)<<"vy*"<<setw(15)<<"Gamma x*"<<setw(15)<<"Gamma y*"<<setw(15)<<"Energ tot*"<<endl;
    cout<<"***********************************************************************************************************************"<<endl;
    for(int i=0; i<1000; i++)
    {
        t0=t0+h;
        vmx=vx-0.5*x*GM/(r*r*r)*h;
        vmy=vy-0.5*y*GM/(r*r*r)*h;
        ym=y+0.5*vy*h;
        xm=x+0.5*vx*h;
        gamx=-xm*GM/(r*r*r);
        gamy=-ym*GM/(r*r*r);
        vx=vx+gamx*h;
        vy=vy+gamy*h;
        y=y+vmy*h;
        x=x+vmx*h;
                                        ///* Calcule de l'Energie Totale*/
        E=0.5*(vx*vx+vy*vy)-GM*m/r;
       if(monFlux)
          {
             monFlux2<<setw(8)<<t0<<setw(15)<<x<<setw(15)<<y<<setw(15)<<vx<<setw(15)<<vy<<setw(15)<<E<<endl;
             cout<<setw(8)<<t0<<setw(15)<<x<<setw(15)<<y<<setw(15)<<vx<<setw(15)<<vy<<setw(15)<<GM*x/(r*r*r)<<setw(15)<<GM*y/(r*r*r)<<setw(15)<<E<<endl;

          }
        else
          {
             cout << "ERREUR: Impossible d’ouvrir le fichier." << endl;
          }

    }

      monFlux2.close();

    /// Question 4:
                                                ///* Mini-système solaire: Application de la méthode d'Euler Richarson*/


    // Nom du fichier
        string nomFichier3("data3.txt");
               //D´eclaration du flux
        ofstream monFlux3(nomFichier3.c_str());
    t0=0;
    //la distance qui sépare les deux objets
    r1=sqrt(x1*x1+y1*y1);
    r2=sqrt(x2*x2+y2*y2);
    r21=r2-r1;
    vy1=sqrt(GM1/r1);
    vy2=sqrt(GM2/r2);
            cout<<"--- Mini-système solaire: Aplication de la méthode de d'Euler Richardson---"<<endl;
    cout<<"***********************************************************************************************************************"<<endl;
    cout<<setw(8)<<"Temps*"<<setw(15)<<"Abs x*"<<setw(15)<<"Abs y*"<<setw(15)<<"vx*"<<setw(15)<<"vy*"<<setw(15)<<"x2*"<<setw(15)<<"y2*"<<endl;
    cout<<"***********************************************************************************************************************"<<endl;
    for(int i=0; i<2400; i++)
    {
        t0=t0+h;
        vmx1=vx1-0.5*h*(x1*GM1/(r1*r1*r1)+Gm2*(x2-x1)/(r21*r21*r21));
        vmy1=vy1-0.5*h*(y1*GM1/(r1*r1*r1)+Gm2*(y2-y1)/(r21*r21*r21));
        vmx2=vx2-0.5*h*(x2*GM2/(r2*r2*r2)-Gm1*(x2-x1)/(r21*r21*r21));
        vmy2=vy2-0.5*h*(y2*GM2/(r2*r2*r2)-Gm1*(y2-y1)/(r21*r21*r21));
        ym1=y1+0.5*vy1*h;
        xm1=x1+0.5*vx1*h;
        ym2=y2+0.5*vy2*h;
        xm2=x2+0.5*vx2*h;
        gamx1=-xm1*GM1/(r1*r1*r1)+Gm2*(x2-x1)/(r21*r21*r21);
        gamy1=-ym1*GM1/(r1*r1*r1)+Gm2*(y2-y1)/(r21*r21*r21);
        gamx2=-xm2*GM2/(r2*r2*r2)-Gm1*(x2-x1)/(r21*r21*r21);
        gamy2=-ym2*GM2/(r2*r2*r2)-Gm1*(y2-y1)/(r21*r21*r21);
        vx1=vx1+gamx1*h;
        vy1=vy1+gamy1*h;
        vx2=vx2+gamx2*h;
        vy2=vy2+gamy2*h;
        y1=y1+vmy1*h;
        x1=x1+vmx1*h;
        y2=y2+vmy2*h;
        x2=x2+vmx2*h;

       if(monFlux)
          {
             monFlux3<<setw(8)<<t0<<setw(15)<<x1<<setw(15)<<y1<<setw(15)<<vx1<<setw(15)<<vy1<<setw(15)<<x2<<setw(15)<<y2<<endl;
             cout<<setw(8)<<t0<<setw(15)<<x1<<setw(15)<<y1<<setw(15)<<vx1<<setw(15)<<vy1<<setw(15)<<x2<<setw(15)<<y2<<endl;

          }
        else
          {
             cout << "ERREUR: Impossible d’ouvrir le fichier." << endl;
          }

    }

    }
