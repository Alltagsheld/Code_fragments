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
    Field* spawnField(int length, int width);
    void spawnArray(int length, int width);
    void startGame();
    void rules(int length, int width);
    void loadFile(bool glider);
    void deleteArray();
private:
    vector <Field*> fieldVector;
};

#endif // GAMEOFLIFE_H
