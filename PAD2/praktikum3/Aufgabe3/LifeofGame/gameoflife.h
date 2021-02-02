#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include "field.h"
#include <iostream>
#include <vector>

using namespace std;

class GameOfLife
{
public:
    GameOfLife();
    ~GameOfLife();
    Field* spawnField(const int length,const int width);
    void spawnArray(int length, int width);
    void startGame(const bool skip, Field &game);
    void rules(int length, int width);
    void loadFile(const bool skip,bool glider);
    void deleteArray();
    void getDimension(const bool skip);
private:
    vector <Field*> fieldVector;
};

#endif // GAMEOFLIFE_H
