#include "cell.h"

Cell::Cell()
{

}
void Cell::setStatus(bool status)
{
    this->status= status;
}
bool Cell::getStatus()
{
    return this->status;
}
