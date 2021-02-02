#include "geschenke.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<Geschenke*>geschenkeListe;
    bool repeat = true;

    do
    {
        int auswahl;
        std::string name;
        cout << "Hi, was geht ab.\nsag mir doch welchen Koerper du verpacken willst, wenn du Glueck hast sage ich dir wieviel Papier du brauchst.\n" << endl;
        cout <<"(1)Zylinder\n(2)Kugel\n(3)Paket\n(4)Ergebnisse Ausgeben\n(5)Exit\n"<<endl;
        cin>>auswahl;

        if(auswahl!=4&& auswahl !=5)
        {
            cout<<"gib ihm doch einen Namen!\nObjektname: ";
            cin>>name;
            cout << endl;
        }

        switch(auswahl)
        {
        case 1:
        {
            double hoehe, radius;
            string form = "Zylinder";
            cout<<"Hoehe des Zylinders?"<<endl;
            cin>>hoehe;
            cout<<"Radius des Zylinders?"<<endl;
            cin>>radius;
            Geschenke *a = new Zylinder (name,form, hoehe, radius);
            geschenkeListe.push_back(a);
            break;
        }
        case 2:
        {
            double radius;
            string form = "Kugel";
            cout<<"Radius der Kugel?"<<endl;
            cin>>radius;
            Geschenke *a = new Kugel (name,form, radius);
            geschenkeListe.push_back(a);
            break;
        }
        case 3:
        {
            double breite, hoehe, laenge;
            string form = "Paket";
            cout<<"laenge des Pakets?"<<endl;
            cin>>laenge;
            cout<<"Breite des Pakets?"<<endl;
            cin>>breite;
            cout<<"Hoehe des Pakets?"<<endl;
            cin>>hoehe;
            Geschenke* a = new Paket (name,form, breite, hoehe, laenge);
            geschenkeListe.push_back(a);
            break;
        }
        case 4:
        {
            system("cls");
            for(unsigned int i=0; i<geschenkeListe.size(); i++)
            {
                cout << "Form: "<< geschenkeListe.at(i)->getForm() <<"\tName: "<<geschenkeListe.at(i)->getName()<< "\t du brauchst "<<geschenkeListe.at(i)->einpacken()<<" cm^2 Geschenkpapier"<<endl;
            }
            break;
        }
        case 5:
            repeat = false;
            for(unsigned int i=geschenkeListe.size(); i>0; i--)
            {
                geschenkeListe.at(i-1)->~Geschenke();
            }
            break;
        default:
            break;
        }
    }while(repeat);

    return 0;
}
