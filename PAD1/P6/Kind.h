#ifndef KIND_H
#define KIND_H
#include "Angebot.h"
#include <iostream>

using namespace std;

class Kind
{
public:
    Kind(string a, string b);
    void print();
private:
    string vorname;
    string nachname;
};

#endif // KIND_H
