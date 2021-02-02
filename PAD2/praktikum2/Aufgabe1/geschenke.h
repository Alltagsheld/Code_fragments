#ifndef GESCHENKE_H
#define GESCHENKE_H
#include <string>
#include <math.h>


class Geschenke
{
public:
    Geschenke();
    virtual~Geschenke();
    virtual double einpacken();
    std::string getName();
    std::string getForm();
    double breite, hoehe, laenge, radius, oberflaeche;
    std::string name;
    std::string form;
};

class Zylinder:public Geschenke
{
public:
    Zylinder(std::string name, std::string form,double hoehe,double radius);
    ~Zylinder();
    double einpacken();
};

class Kugel:public Geschenke
{
public:
    Kugel(std::string name,std::string form, double radius);
    ~Kugel();
    double einpacken();
};

class Paket:public Geschenke
{
public:
    Paket(std::string name,std::string form, double breite,double hoehe,double laenge);
    ~Paket();
    double einpacken();
};

#endif // GESCHENKE_H
