#include "tower.h"
#include <QString>

Tower::Tower()
{

}
int Tower::size()
{
    return this->c.size();
}
int Tower::at(int pos)
{
    std::stack<int> tmp;
    for(int i=0; i<pos; i++)
    {
        int a = this->top();
        this->pop();
        tmp.push(a);
    }
    int at = this->top();
    while(!tmp.empty())
    {
        int a=tmp.top();
        tmp.pop();
        this->push(a);
    }
    return at;
}
void Tower::push(int disc)
{
    this->c.push_back(disc);
}
void Tower::deleteStack()
{
    while(!this->empty())
    {
        this->pop();
    }
}
