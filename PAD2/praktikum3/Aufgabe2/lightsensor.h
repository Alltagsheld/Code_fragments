#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H
#include "knots.h"


class Lightsensor :public Knots
{
public:
    Lightsensor();
    int getCondition() override;
    int getID()override;
private:
    void setCondition() override;
    static int ID;
    int instanz_ID;
};

#endif // LIGHTSENSOR_H
