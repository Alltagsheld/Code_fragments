#include "ferienprogramm.h"
#include <vector>
#include <iostream>
#include "angebot.h"
using namespace std;

Ferienprogramm::Ferienprogramm()
{

}

void mainDialog()
{
    cout <<"Willkommen zum Kinderferienprogramm der Stadt Darmstadt. \n" <<
           "Ihnen stehen folgende Funktionen zur Verfuegung: \n" << endl <<
           "1: Neues Angebot eintragen \n2: Alle Angebote anzeigen \n3: Kind fuer ein Angebot anmelden\n"
        << "4: Buchungsliste fuer ein Angebot anzeigen \n5: Angebot loeschen\n" << endl << "0: Zum Beenden des Programmes\n" << endl;
}
