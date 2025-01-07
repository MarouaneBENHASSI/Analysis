/// ce code calcule les énergies classiques d'un Oscillateur Harmonique


#include <iostream> // flux vers ´ecran
#include <fstream> // flux vers fichier
#include <cmath>

using namespace std;

int main()
{
    float t, vn, vm, xn, xm, omega2, m, gamman, gammam, En, E0, h, k, kf;

/// Methode d'Euler-Richardson
    h=0.0001;
    m=10;
    xn=1;
    vn=0;
    omega2=9. ;
    E0=0.5*m*vn*vn+0.5*omega2*m*xn*xn;
    ///E0=0.5*omega2*m*xn*xn;
    string nomFichier2("data2.txt");
    ofstream monFlux2(nomFichier2.c_str());

    cout<<"--- Methode d'Euler-Richardson"<<endl;
    for(float t=0; t<1; t=t+h)
    {
        gamman=-omega2*xn;
        vm=vn+0.5*gamman*h;
        xm=xn+0.5*vn*h;
        gammam=-omega2*xm;

        vn=vn+gammam*h;
        xn=xn+vm*h;

        En=0.5*m*vn*vn+0.5*omega2*m*xn*xn;
           /// En=0.5*omega2*m*xn*xn;
        if(monFlux2)
          {monFlux2<< En-E0 <<"   "<<t<<endl;
          }
        else
          {cout << "ERREUR: Impossible d’ouvrir le fichier." << endl;
          }

    }

      monFlux2.close();


/// Question 3: Methode d'Euler
    xn=1;
    vn=0;
    omega2=9. ;
    E0=0.5*m*vn*vn+0.5*omega2*m*xn*xn;
    string nomFichier1("data1.txt");
    ofstream monFlux1(nomFichier1.c_str());

    cout<<"--- Methode d'Euler"<<endl;
    for(float t=0; t<1; t=t+h)
    {
        gamman=-omega2*xn;
        xn=xn+vn*h;
        vn=vn+gamman*h;

        En=0.5*m*vn*vn+0.5*omega2*m*xn*xn;
           /// En=0.5*omega2*m*xn*xn;
        if(monFlux1)
          {monFlux1<< En-E0 <<"   "<<t<<endl;
          }
        else
          {cout << "ERREUR: Impossible d’ouvrir le fichier." << endl;
          }

    }

      monFlux1.close();


/// Question 4: x(t) et v(t) dans l'espace des phases
    xn=1;
    h=0.0001;
    vn=0;
    omega2=9. ;
    string nomFichier3("data3.txt");
    ofstream monFlux3(nomFichier3.c_str());

    cout<<"--- Methode d'Euler pour determiner x(t) et v(t)"<<endl;
    for(float t=0; t<11; t=t+h)
    {
        gamman=-omega2*xn;
        vn=vn+gamman*h;
        xn=xn+vn*h;

        if(monFlux3)
          {monFlux3<< xn <<"   "<< vn <<"  "<< t <<endl;
          }
        else
          {cout << "ERREUR: Impossible d’ouvrir le fichier." << endl;
          }

    }

      monFlux1.close();

/// Question 5: Oscillateur amortie
    h=0.001;
    m=10;
    xn=1;
    vn=0;
    omega2=9. ;
    kf=0.5;
    string nomFichier5("data5.txt");
    ofstream monFlux5(nomFichier5.c_str());

    cout<<"--- Oscillateur Harmonique Amortie"<<endl;
    for(float t=0; t<1; t=t+h)
    {
        gamman=-omega2*xn-kf*vn;
        vm=vn+0.5*gamman*h;
        xm=xn+0.5*vn*h;
        gammam=-omega2*xm-kf*vn;

        vn=vn+gammam*h;
        xn=xn+vm*h;

        if(monFlux5)
          {monFlux5<< xn <<"   "<<vn<<"  "<<t<<endl;
          }
        else
          {cout << "ERREUR: Impossible d’ouvrir le fichier." << endl;
          }

    }

      monFlux5.close();


/// Question 6: Système de forces extérieure
    h=0.001;
    m=10;
    xn=1;
    vn=0;
    omega2=9. ;
    kf=0.5;
    string nomFichier6("data6.txt");
    ofstream monFlux6(nomFichier6.c_str());

    cout<<"--- Système de forces extérieure "<<endl;
    for(float t=0; t<1; t=t+h)
    {
        gamman=-omega2*xn-kf*vn+1./acos(-1)+0.5*cos(t)+(2/(3*acos(-1)))*cos(2*t)-(2/(15*acos(-1)))*cos(4*t);
        vm=vn+0.5*gamman*h;
        xm=xn+0.5*vn*h;
        gammam=-omega2*xm-kf*vn+1./acos(-1)+0.5*cos(t)+(2/(3*acos(-1)))*cos(2*t)-(2/(15*acos(-1)))*cos(4*t);

        vn=vn+gammam*h;
        xn=xn+vm*h;

        if(monFlux6)
          {monFlux6<< xn <<"   "<<vn<<"  "<<t<<endl;
          }
        else
          {cout << "ERREUR: Impossible d’ouvrir le fichier." << endl;
          }

    }

      monFlux6.close();

    }
