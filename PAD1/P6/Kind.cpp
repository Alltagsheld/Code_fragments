#include "Kind.h"
#include "Angebot.h"
#include "Ferienprogramm.h"

Kind::Kind(string a, string b)
{
    vorname = a;
    nachname = b;
}
void Kind::print()
{
    cout << vorname <<"\t" << nachname << endl;
}
