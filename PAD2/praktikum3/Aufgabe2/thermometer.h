#ifndef THERMOMETER_H
#define THERMOMETER_H
#include "knots.h"

class Thermometer : public Knots
{
public:
    Thermometer();
    int getCondition() override;
    int getID()override;
private:
    void setCondition() override;
    static int ID;
    int instanz_ID;
};

#endif // THERMOMETER_H
