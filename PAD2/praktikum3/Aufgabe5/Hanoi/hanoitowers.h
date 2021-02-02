#ifndef HANOITOWERS_H
#define HANOITOWERS_H

#include <QMainWindow>
#include "tower.h"
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class hanoiTowers; }
QT_END_NAMESPACE

class hanoiTowers : public QMainWindow
{
    Q_OBJECT

public:
    hanoiTowers(QWidget *parent = nullptr);
    ~hanoiTowers();
    QString print(Tower &T);
private slots:
    void setupDisc();
    void moveDisc(Tower &Ts, Tower&Tg);
    bool rulesNotViolated(Tower &Ts, Tower&Tg);
    void on_T1T2_clicked();
    void on_T1T3_clicked();
    void on_restartBtn_clicked();
    void on_exitBtn_clicked();
    void on_T2T3_clicked();
    void on_T2T1_clicked();
    void on_T3T1_clicked();
    void on_T3T2_clicked();

private:
    Tower T1;
    Tower T2;
    Tower T3;
    Ui::hanoiTowers *ui;
};
#endif // HANOITOWERS_H
