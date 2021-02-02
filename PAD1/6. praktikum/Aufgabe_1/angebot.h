#ifndef ANGEBOT_H
#define ANGEBOT_H
#include <string>
#include "kind.h"
using namespace std;


class Angebot
{
public:
    Angebot();
    void kindAufnehmen (Kind* kind);
private:
    int freiePlaetze();
    bool istVoll ();
    int platze;
    string titel;
    int id;
    bool voll;

    int size=0;
    Kind** teilnehmer = new Kind* [size];
};



#endif // ANGEBOT_H
