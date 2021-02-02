#include "lightsensor.h"
#include <stdlib.h>
#include <time.h>

int Lightsensor::ID =0;

Lightsensor::Lightsensor()
{
    type = "lightsensor";
    ID++;
    instanz_ID = ID;
    setCondition();
}
void Lightsensor::setCondition()
{
    srand(time(NULL));
    condition = rand()% 1+ 12000;
}
int Lightsensor::getCondition()
{
    return condition;
}
int Lightsensor::getID()
{
    return instanz_ID;
}
