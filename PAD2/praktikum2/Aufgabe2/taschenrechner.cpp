#include "taschenrechner.h"
#include "ui_taschenrechner.h"



Taschenrechner::Taschenrechner(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Taschenrechner)
{
    ui->setupUi(this);
    //wenn ok gedrückt wird, rufe onCalculateClicked auf
    /*connect (ui->buttonBox, &QDialogButtonBox::accepted,
             this, &Taschenrechner::on_Calculate_Clicked);*/
}
void Taschenrechner::on_Calculate_Clicked()
{
    double a,b,c;
    bool ok1, ok2;
    QString output;

    a=ui->Eingabe1->text().toDouble(&ok1);
    b= ui->Eingabe2->text().toDouble(&ok2);

    if(ok1 and ok2)
    {
        c= a+b;
        output = QString("%1").arg(c);
    }
    else
        output = QString ("Falsche Eingabe");

    //ui->Summe->setText(output);
    ui->LabelErgebnis->setText(output);
}

void Taschenrechner::on_Eingabe1_textChanged(const QString &arg1)
{
    on_Calculate_Clicked();
}

void Taschenrechner::on_Eingabe2_textChanged(const QString &arg1)
{
    on_Calculate_Clicked();
}

Taschenrechner::~Taschenrechner()
{
    delete ui;
}
void Taschenrechner::on_pushButton_clicked()
{
    on_Calculate_Clicked();
}
