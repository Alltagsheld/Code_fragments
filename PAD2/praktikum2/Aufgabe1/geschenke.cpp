#include "geschenke.h"
#include <iostream>
#include "math.h"

using std::cout, std::endl;

Geschenke::Geschenke()
{

}
Geschenke::~Geschenke()
{
    cout<<"Geschenk destroyed"<<endl;
}
double Geschenke::einpacken()
{

}
std::string Geschenke::getName()
{
    return this->name;
}
std::string Geschenke::getForm()
{
    return this->form;
}
Zylinder::Zylinder(std::string name,std::string form,double hoehe,double radius)
{
    this->form = form;
    this->hoehe = hoehe;
    this->radius = radius;
    this->name = name;
}
Zylinder::~Zylinder()
{
    cout <<"Zylinder destroyed!" << endl;
}
double Zylinder::einpacken()
{
    this->oberflaeche = 2*M_PI*radius*(radius*hoehe);
    return oberflaeche;
}
Kugel::Kugel(std::string name,std::string form, double radius)
{
    this->form = form;
    this->radius = radius;
    this->name = name;
}
Kugel::~Kugel()
{
    cout <<"Kugel destroyed!" << endl;
}
double Kugel::einpacken()
{
    this->oberflaeche = M_PI*4*pow(radius, 2);
    return oberflaeche;
}
Paket::Paket(std::string name,std::string form, double breite,double hoehe,double laenge)
{
    this->form = form;
    this->breite = breite;
    this->hoehe = hoehe;
    this->laenge = laenge;
    this->name = name;
}
Paket::~Paket()
{
    cout <<"Paket destroyed!" << endl;
}
double Paket::einpacken()
{
    this->oberflaeche= 2*laenge*breite + 2*laenge*hoehe + 2*breite*hoehe;
    return oberflaeche;
}
