#ifndef TOWER_H
#define TOWER_H
#include <stack>

class Tower:public std::stack<int>
{
public:
    Tower();
    //bool check(int disc); //check if disc can be placed on tower //its in rules now
    int size();             //returns size
    int at(int pos);        //returns disc value at pos
    void push(int disc);    //pushes disc to tower
    void deleteStack();     //empties stack

};

#endif // TOWER_H
