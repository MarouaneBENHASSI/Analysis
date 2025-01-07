#include<iostream>
#include<iomanip>
#include<cmath>
#include<fstream>

using namespace std;

main()
{
/// Question number 1
    float V0(2.), u(0.), v(0.), dt(0.1), ro(0.), A(0.), x(0.), x0(-10.), k0(2.), omega(1.), dx(0.4), xmin(-20.), xmax(+20.), nabla(1.);
    A=pow(1/(2*acos(-1)),0.25);

    string nomFichier1("data11.txt");
    ofstream monFlux1(nomFichier1.c_str());

        x=-20.;
    for(int i=0; i<100; i++)
    {
        u=A*cos(k0*(x-x0))*exp(-pow((x-x0),2)/(4*pow(omega,2)));
        v=A*sin(k0*(x-x0)-omega*dt/2.)*exp(-pow((x-x0-omega*dt/k0),2)/(4*pow(omega,2)));

        ro=u*u+v*v;
        monFlux1<<setw(8)<<x<<setw(15)<<ro<<endl;
        cout<<setw(8)<<x<<setw(15)<<ro<<endl;
        x=x+dx;
    }


}
