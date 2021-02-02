/********************************************************************************
** Form generated from reading UI file 'taschenrechner.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASCHENRECHNER_H
#define UI_TASCHENRECHNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Taschenrechner
{
public:
    QWidget *centralwidget;
    QLabel *LabelEingabe1;
    QLabel *LabelEingabe2;
    QLabel *LabelSumme;
    QLineEdit *Eingabe1;
    QLineEdit *Eingabe2;
    QDialogButtonBox *buttonBox;
    QLabel *LabelErgebnis;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Taschenrechner)
    {
        if (Taschenrechner->objectName().isEmpty())
            Taschenrechner->setObjectName(QString::fromUtf8("Taschenrechner"));
        Taschenrechner->resize(603, 522);
        Taschenrechner->setMaximumSize(QSize(603, 522));
        Taschenrechner->setAutoFillBackground(true);
        Taschenrechner->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(Taschenrechner);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        LabelEingabe1 = new QLabel(centralwidget);
        LabelEingabe1->setObjectName(QString::fromUtf8("LabelEingabe1"));
        LabelEingabe1->setGeometry(QRect(220, 180, 47, 14));
        LabelEingabe2 = new QLabel(centralwidget);
        LabelEingabe2->setObjectName(QString::fromUtf8("LabelEingabe2"));
        LabelEingabe2->setGeometry(QRect(220, 210, 47, 14));
        LabelSumme = new QLabel(centralwidget);
        LabelSumme->setObjectName(QString::fromUtf8("LabelSumme"));
        LabelSumme->setGeometry(QRect(220, 240, 50, 14));
        Eingabe1 = new QLineEdit(centralwidget);
        Eingabe1->setObjectName(QString::fromUtf8("Eingabe1"));
        Eingabe1->setGeometry(QRect(280, 180, 113, 20));
        Eingabe2 = new QLineEdit(centralwidget);
        Eingabe2->setObjectName(QString::fromUtf8("Eingabe2"));
        Eingabe2->setGeometry(QRect(280, 210, 113, 20));
        buttonBox = new QDialogButtonBox(centralwidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setEnabled(true);
        buttonBox->setGeometry(QRect(260, 290, 156, 23));
        buttonBox->setAutoFillBackground(false);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel);
        buttonBox->setCenterButtons(false);
        LabelErgebnis = new QLabel(centralwidget);
        LabelErgebnis->setObjectName(QString::fromUtf8("LabelErgebnis"));
        LabelErgebnis->setGeometry(QRect(280, 240, 47, 14));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 290, 75, 23));
        Taschenrechner->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Taschenrechner);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 603, 22));
        Taschenrechner->setMenuBar(menubar);
        statusbar = new QStatusBar(Taschenrechner);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Taschenrechner->setStatusBar(statusbar);

        retranslateUi(Taschenrechner);
        QObject::connect(buttonBox, SIGNAL(rejected()), Taschenrechner, SLOT(close()));

        QMetaObject::connectSlotsByName(Taschenrechner);
    } // setupUi

    void retranslateUi(QMainWindow *Taschenrechner)
    {
        Taschenrechner->setWindowTitle(QCoreApplication::translate("Taschenrechner", "Taschenrechner", nullptr));
        LabelEingabe1->setText(QCoreApplication::translate("Taschenrechner", "Eingabe1", nullptr));
        LabelEingabe2->setText(QCoreApplication::translate("Taschenrechner", "Eingabe2", nullptr));
        LabelSumme->setText(QCoreApplication::translate("Taschenrechner", "Summe", nullptr));
        LabelErgebnis->setText(QString());
        pushButton->setText(QCoreApplication::translate("Taschenrechner", "Berechnen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Taschenrechner: public Ui_Taschenrechner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASCHENRECHNER_H
