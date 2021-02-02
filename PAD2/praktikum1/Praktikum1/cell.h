#ifndef CELL_H
#define CELL_H


class Cell
{
public:
    Cell();
    void setStatus(bool status);
    bool getStatus();
private:
    bool status = false;
};

#endif // CELL_H
