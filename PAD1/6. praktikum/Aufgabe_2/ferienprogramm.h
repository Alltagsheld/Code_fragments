#ifndef FERIENPROGRAMM_H
#define FERIENPROGRAMM_H
#include <vector>
#include <iostream>
#include "angebot.h"


class Ferienprogramm
{
public:
    Ferienprogramm(int programm_start, int programm_ende);

    void angebotLoeschen();
    int setStart(int programm_start);
    void getStart();
    int setEnde(int programm_ende);
    void mainDialog();
    void kindAnmelden();
    void angebotEintragen();
    void angebotAnzeigen();
    void buchungslisteAusgeben();
    bool isNoInt();
private:
    vector <Kind*> kinderListe;
    vector <Angebot*> angebotsListe;
    int start;
    int ende;
};

#endif // FERIENPROGRAMM_H
