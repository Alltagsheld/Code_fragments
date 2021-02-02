#include "gateway.h"
#include "knots.h"
#include "lightsensor.h"
#include "thermometer.h"
#include "switch.h"
#include <iostream>

using namespace std;

Gateway::Gateway()
{
    setupVector();
}
void Gateway::setupVector()
{
    Lightsensor *a = new Lightsensor();
    Thermometer *b = new Thermometer();
    Thermometer *c = new Thermometer();
    Switch *d = new Switch();
    Switch *e = new Switch();
    knotVector.push_back(a);
    knotVector.push_back(b);
    knotVector.push_back(c);
    knotVector.push_back(d);
    knotVector.push_back(e);
}
void Gateway::menu()
{
    bool repeat = true;
    do
    {
        cout <<"Welcome, friend.\n\n(1)read thermometer\n(2)read lightsensor\n(3)read switch\n(4)set switch\n(5)exit"<<endl;
        int selection;
        cin >>selection;
        system("cls");
        switch (selection)
        {
        case 1:
        {
            for(unsigned int i=0; i<knotVector.size();i++)
            {
                Knots *a = knotVector.at(i);
                if(a->getType()=="thermometer")
                {
                    cout <<a->getID()<<"\t" << a->getType()<<"\tit's condition is "<<a->getCondition()<<" degree celsius"<<endl;
                }
            }
            break;
        }
        case 2:
        {
            for(unsigned int i=0; i<knotVector.size();i++)
            {
                Knots *a = knotVector.at(i);
                if(a->getType()=="lightsensor")
                {
                    cout <<a->getID()<<"\t" << a->getType()<<"\tit's condition is "<<a->getCondition()<<" lux"<<endl;
                }
            }
            break;
        }
        case 3:
        {
            for(unsigned int i=0; i<knotVector.size();i++)
            {
                Knots *a = knotVector.at(i);
                if(a->getType()=="switch")
                {
                    cout <<a->getID()<<"\t" << a->getType()<<"\tit's condition is ";
                    if(a->getCondition()==1)
                    {
                        cout <<" active"<<endl;
                    }
                    if(a->getCondition()==0)
                    {
                        cout <<" inactive"<<endl;
                    }
                }
            }
            break;
        }
        case 4:
        {
            for(unsigned int i=0; i<knotVector.size();i++)
            {
                Knots *a = knotVector.at(i);
                if(a->getType()=="switch")
                {
                    a->setCondition();
                    cout <<"condition has been changed. It is now ";
                    if(a->getCondition()==1)
                    {
                        cout <<" active"<<endl;
                    }
                    if(a->getCondition()==0)
                    {
                        cout <<" inactive"<<endl;
                    }
                }
            }
            break;
        }
        case 5:
            repeat = false;
            break;
        default:
            cout <<"sorry, i didn't get that."<<endl;
            break;
        }
    }while(repeat);
}
