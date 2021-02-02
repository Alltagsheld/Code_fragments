#include "angebot.h"
#include "kind.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

long Angebot::all_IDs = 0;

Angebot::Angebot(int a_plaetze, string a_titel, int angebot_start, int angebot_ende)
{   
    setPlaetze(a_plaetze);
    setTitel(a_titel);
    setKW(angebot_start, angebot_ende);
    all_IDs ++;
    instanz_id = all_IDs;
    teilnehmer = new Kind* [plaetze];                         //initialize default array of plaetze size at start

    for(int i=0; i<= getPlaetze(); i++)                          //initialize all elements as pointers to zero
    {
        teilnehmer[i] = nullptr;
    }
    setFreiePlaetze();
}

Angebot::~Angebot()
{
    cout << "Ihr Angebot wurde geloescht." << endl;
}

bool Angebot::isEqual(Angebot* angebot)
{
    return(titel == angebot->getTitel() && plaetze == angebot->getPlaetze() && kw_start == angebot->getKW_start() && kw_ende == angebot->getKW_ende());
}

void Angebot::setKW(int angebot_start, int angebot_ende)
{
    kw_start = angebot_start;
    kw_ende = angebot_ende;
}

int Angebot::getKW_start()
{
    return kw_start;
}
int Angebot::getKW_ende()
{
    return kw_ende;
}

void Angebot::printTeilnehmer()
{
    for(int i=0; i<getPlaetze(); i++)
    {
        if(teilnehmer[i]!=nullptr)
        {
            teilnehmer[i]->print();
        }
    }
}


void Angebot::kindAufnehmen(Kind* kind)
{
    if(!istVoll())
    {
        Kind* x;
        for(int i=0; i< getPlaetze(); i++)                          //initialize all elements as pointers to zero
        {
            x=teilnehmer[i];

            if(teilnehmer[i]!=nullptr)
            {
                if(x->getID()==kind->getID())
                {
                    cout <<"Dieses Kind ist bereits in der Teilnehmerliste." << endl;
                    return;
                }
            }

            if(teilnehmer[i] == nullptr)
            {
                if(i == getPlaetze()-1)
                {
                    voll = true;
                }
                teilnehmer[i] = kind;
                break;
            }
        }
    }
    else
    {
        cout <<"Das Angebot ist voll, Ihr Kind kann nicht aufgenommen werden" << endl;
    }
}

long Angebot::getID()
{
    return instanz_id;
}

void Angebot::setPlaetze(int a_plaetze)
{
    plaetze = a_plaetze;
}

int Angebot::getPlaetze()
{
    return plaetze;
}

void Angebot::setTitel(string a_titel)
{
    titel = a_titel;
}

string Angebot::getTitel()
{
    return titel;
}

int Angebot::freiePlaetze()
{
    int soVieleFreiePlaetze=getPlaetze();

    for(int i=0; i<=getPlaetze(); i++)
    {
        if (teilnehmer[i] != nullptr)
        {
            soVieleFreiePlaetze--;
        }
        /*if(teilnehmer[i] == nullptr)
        {
            soVieleFreiePlaetze;
        }*/
    }
    return soVieleFreiePlaetze;
}

void Angebot::setFreiePlaetze()
{
    instanzFreiePlaetze= freiePlaetze();
}

int Angebot::getFreiePlaetze()
{
    return instanzFreiePlaetze;
}

bool Angebot::istVoll ()
{  
    return voll;
}


