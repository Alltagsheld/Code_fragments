#ifndef FERIENPROGRAMM_H
#define FERIENPROGRAMM_H
#include <vector>
#include <iostream>
#include "angebot.h"


class Ferienprogramm
{
public:
    Ferienprogramm();
    void mainDialog();
    void kindAnmelden();
    void angebotEintragen();
    void angebotAnzeigen();
    vector <Angebot*> angebotsListe;
    vector <Kind*> kinderListe;
};

#endif // FERIENPROGRAMM_H
