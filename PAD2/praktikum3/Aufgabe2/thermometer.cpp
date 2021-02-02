#include "thermometer.h"
#include <stdlib.h>
#include <time.h>

int Thermometer::ID =0;

Thermometer::Thermometer()
{
    type = "thermometer";
    ID++;
    instanz_ID = ID;
    setCondition();
}
void Thermometer::setCondition()
{
    srand(time(NULL));
    condition = rand()% -20 + 20;
}
int Thermometer::getCondition()
{
    return condition;
}
int Thermometer::getID()
{
    return instanz_ID;
}
