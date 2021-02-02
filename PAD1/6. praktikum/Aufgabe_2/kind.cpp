#include "kind.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

long Kind:: all_IDs = 0;

Kind::Kind(string vor, string nach, string datum)
{
    setVorname(vor);
    setNachname(nach);
    setGeburtsdatum(datum);
    all_IDs ++;
    instanz_id = all_IDs;
}

long Kind::getID()
{
    return instanz_id;
}

bool Kind::isEqual(Kind kind)
{
    return(vorname == kind.getVorname() && nachname == kind.getNachname() && geburtsdatum == kind.getGeburtsdatum());

}
string Kind::getVorname()
{
    return vorname;
}

string Kind::getNachname()
{
    return nachname;
}

string Kind::getGeburtsdatum()
{
    return geburtsdatum;
}

void Kind::setVorname(string vor)
{
    vorname = vor;
}

void Kind::setNachname(string nach)
{
    nachname = nach;
}

void Kind::setGeburtsdatum(string datum)
{
    geburtsdatum = datum;
}

void Kind::print ()
{
    cout << getID() <<setw(15) << getVorname() << "\t" << setw(15)<< getNachname() << "\t\t" << setw(15) << getGeburtsdatum() << "\n" << endl;
}

