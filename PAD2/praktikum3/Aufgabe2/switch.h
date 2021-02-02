#ifndef SWITCH_H
#define SWITCH_H
#include "knots.h"


class Switch : public Knots
{
public:
    Switch();
    void setCondition() override;
    int getCondition() override;
    int getID()override;
private:
    static int ID;
    int instanz_ID;
};

#endif // SWITCH_H
