#ifndef TASCHENRECHNER_H
#define TASCHENRECHNER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Taschenrechner; }
QT_END_NAMESPACE

class Taschenrechner : public QMainWindow
{
    Q_OBJECT

public:
    Taschenrechner(QWidget *parent = nullptr);
    ~Taschenrechner();

private slots:
    void on_Calculate_Clicked();

    void on_Eingabe1_textChanged(const QString &arg1);

    void on_Eingabe2_textChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::Taschenrechner *ui;
};
#endif // TASCHENRECHNER_H
