#include "Kind.h"
#include "Ferienprogramm.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Ferienprogramm a;
    Kind* b;
    a.kinderListe.push_back(b);

    for(unsigned int i =0; i< a.kinderListe.size(); i++)
    {
        a.kinderListe.at(i)->print();
    }
    cout << "Hello World!" << endl;
    return 0;
}
