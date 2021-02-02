#ifndef ANGEBOT_H
#define ANGEBOT_H
#include <string>
#include "kind.h"
using namespace std;


class Angebot
{
public:
    Angebot(int a_plaetze, string a_titel, int angebot_start, int angebot_ende);     // Konstruktor
    ~Angebot(); // Destruktor

    void setPlaetze(int a_plaetze);
    void setTitel(string a_titel);
    void setKW(int angebot_start, int angebot_ende);
    bool isEqual(Angebot* angebot);
    int getKW_start ();
    int getKW_ende();
    long getID();
    void setFreiePlaetze();
    int getFreiePlaetze();
    int freiePlaetze();
    int getPlaetze();
    string getTitel();
    void kindAufnehmen (Kind* kind);
    void angebotEintragen();
    bool istVoll ();
    void printTeilnehmer();

private:
    int kw_start;
    int kw_ende;
    Kind **teilnehmer;
    int instanzFreiePlaetze;
    static long all_IDs;
    long instanz_id;
    int plaetze;
    string titel;
    bool voll;

};



#endif // ANGEBOT_H
