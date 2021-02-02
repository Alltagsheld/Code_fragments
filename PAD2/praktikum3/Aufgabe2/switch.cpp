#include "knots.h"
#include "switch.h"
#include <type_traits>
using namespace std;

int Switch::ID = 0;

Switch::Switch()
{
    type = "switch";
    ID++;
    instanz_ID = ID;
    condition = 0;
}
void Switch::setCondition()
{
    if(condition==0)
    {
        condition = 1;
    }
    if(condition==1)
    {
        condition = 0;
    }
}
int Switch::getCondition()//ok lets try this
{
    return condition;
}
int Switch::getID()
{
    return instanz_ID;
}
