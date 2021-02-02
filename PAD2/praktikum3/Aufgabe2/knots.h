#ifndef KNOTS_H
#define KNOTS_H
#include <string>
using std::string;


class Knots
{
public:
    Knots();
    virtual int getCondition()=0;
    virtual void setCondition()=0;
    virtual int getID()=0;
    string getType();
    int condition;
    string type;
};

#endif // KNOTS_H
