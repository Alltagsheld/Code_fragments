#ifndef GATEWAY_H
#define GATEWAY_H
#include <vector>
#include "knots.h"

using std::vector;

class Gateway
{
public:
    Gateway();
    void menu();
    void setupVector();
    vector <Knots*> knotVector;
};

#endif // GATEWAY_H
