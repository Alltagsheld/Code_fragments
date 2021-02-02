#include "tower.h"
#include "hanoitowers.h"
#include <QString>
#include <iostream>
#include "ui_hanoitowers.h"

hanoiTowers::hanoiTowers(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::hanoiTowers)
{
    ui->setupUi(this);
    setupDisc();
    ui->T1label->setStyleSheet("QLabel { background-color : white;}");
    ui->T2label->setStyleSheet("QLabel { background-color : white;}");
    ui->T3label->setStyleSheet("QLabel { background-color : white;}");
    QFont f( "Arial", 10, QFont::Bold);
    ui->T1label->setFont( f);
    ui->T2label->setFont( f);
    ui->T3label->setFont( f);
}
hanoiTowers::~hanoiTowers()
{
    delete ui;
}

void hanoiTowers::moveDisc(Tower &Ts, Tower&Tg)
{
    int a = Ts.top();
    Ts.pop();
    Tg.push(a);
}
bool hanoiTowers::rulesNotViolated(Tower &Ts, Tower&Tg)
{
    if(Ts.size()==0)
    {
        return false;
    }
    if(!Tg.empty())
    {
        if(Ts.top()>Tg.top())
        {
            return false;
        }
    }
    return true;
}
void hanoiTowers::setupDisc()
{
    for(unsigned int i=5; i>=1; i--)
    {
        T1.push(i);
    }
    QString output = print(T1);
    ui->T1label->setText(output);
    output = "";
    ui->T2label->setText(output);
    ui->T3label->setText(output);
}
QString hanoiTowers::print(Tower &T)
{
    QString output;

    for(int i=0; i<T.size(); i++)
    {
        output.append("\n");
        output.append(QString ::number(T.at(i)));
        output.append("\n");
    }
    return output;
}

void hanoiTowers::on_restartBtn_clicked()
{
    T1.deleteStack();
    T2.deleteStack();
    T3.deleteStack();
    setupDisc();
}

void hanoiTowers::on_exitBtn_clicked()
{
    close();
}

void hanoiTowers::on_T1T2_clicked()
{
    if(rulesNotViolated(T1, T2))
    {
        moveDisc(T1, T2);
        QString output = print(T1);
        ui->T1label->setText(output);
        output = print(T2);
        ui->T2label->setText(output);
    }
}

void hanoiTowers::on_T1T3_clicked()
{
    if(rulesNotViolated(T1, T3))
    {
        moveDisc(T1, T3);
        QString output = print(T1);
        ui->T1label->setText(output);
        output = print(T3);
        ui->T3label->setText(output);
    }

}

void hanoiTowers::on_T2T1_clicked()
{
    if(rulesNotViolated(T2, T1))
    {
        moveDisc(T2, T1);
        QString output = print(T2);
        ui->T2label->setText(output);
        output = print(T1);
        ui->T1label->setText(output);
    }
}

void hanoiTowers::on_T2T3_clicked()
{
    if(rulesNotViolated(T2, T3))
    {
        moveDisc(T2, T3);
        QString output = print(T2);
        ui->T2label->setText(output);
        output = print(T3);
        ui->T3label->setText(output);
    }
}

void hanoiTowers::on_T3T1_clicked()
{
    if(rulesNotViolated(T3, T1))
    {
        moveDisc(T3, T1);
        QString output = print(T3);
        ui->T3label->setText(output);
        output = print(T1);
        ui->T1label->setText(output);
    }
}

void hanoiTowers::on_T3T2_clicked()
{
    if(rulesNotViolated(T3, T2))
    {
        moveDisc(T3, T2);
        QString output = print(T3);
        ui->T3label->setText(output);
        output = print(T2);
        ui->T2label->setText(output);
    }
}
