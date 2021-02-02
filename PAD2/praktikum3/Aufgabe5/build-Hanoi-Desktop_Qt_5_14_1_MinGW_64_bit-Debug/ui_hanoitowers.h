/********************************************************************************
** Form generated from reading UI file 'hanoitowers.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANOITOWERS_H
#define UI_HANOITOWERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hanoiTowers
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *T1T2;
    QPushButton *T1T3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *T2T3;
    QPushButton *T2T1;
    QVBoxLayout *verticalLayout_3;
    QPushButton *T3T1;
    QPushButton *T3T2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *restartBtn;
    QPushButton *exitBtn;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *T1label;
    QVBoxLayout *verticalLayout_6;
    QLabel *T2label;
    QVBoxLayout *verticalLayout_5;
    QLabel *T3label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *hanoiTowers)
    {
        if (hanoiTowers->objectName().isEmpty())
            hanoiTowers->setObjectName(QString::fromUtf8("hanoiTowers"));
        hanoiTowers->resize(1009, 676);
        centralwidget = new QWidget(hanoiTowers);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(110, 380, 781, 141));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(100);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        T1T2 = new QPushButton(horizontalLayoutWidget);
        T1T2->setObjectName(QString::fromUtf8("T1T2"));

        verticalLayout->addWidget(T1T2);

        T1T3 = new QPushButton(horizontalLayoutWidget);
        T1T3->setObjectName(QString::fromUtf8("T1T3"));

        verticalLayout->addWidget(T1T3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        T2T3 = new QPushButton(horizontalLayoutWidget);
        T2T3->setObjectName(QString::fromUtf8("T2T3"));

        verticalLayout_2->addWidget(T2T3);

        T2T1 = new QPushButton(horizontalLayoutWidget);
        T2T1->setObjectName(QString::fromUtf8("T2T1"));

        verticalLayout_2->addWidget(T2T1);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        T3T1 = new QPushButton(horizontalLayoutWidget);
        T3T1->setObjectName(QString::fromUtf8("T3T1"));

        verticalLayout_3->addWidget(T3T1);

        T3T2 = new QPushButton(horizontalLayoutWidget);
        T3T2->setObjectName(QString::fromUtf8("T3T2"));

        verticalLayout_3->addWidget(T3T2);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(200, 520, 601, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(100);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        restartBtn = new QPushButton(horizontalLayoutWidget_2);
        restartBtn->setObjectName(QString::fromUtf8("restartBtn"));

        horizontalLayout_2->addWidget(restartBtn);

        exitBtn = new QPushButton(horizontalLayoutWidget_2);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));

        horizontalLayout_2->addWidget(exitBtn);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(110, 30, 781, 341));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(150);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        T1label = new QLabel(horizontalLayoutWidget_3);
        T1label->setObjectName(QString::fromUtf8("T1label"));

        verticalLayout_4->addWidget(T1label);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        T2label = new QLabel(horizontalLayoutWidget_3);
        T2label->setObjectName(QString::fromUtf8("T2label"));

        verticalLayout_6->addWidget(T2label);


        horizontalLayout_3->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        T3label = new QLabel(horizontalLayoutWidget_3);
        T3label->setObjectName(QString::fromUtf8("T3label"));
        T3label->setAutoFillBackground(false);

        verticalLayout_5->addWidget(T3label);


        horizontalLayout_3->addLayout(verticalLayout_5);

        hanoiTowers->setCentralWidget(centralwidget);
        menubar = new QMenuBar(hanoiTowers);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1009, 22));
        hanoiTowers->setMenuBar(menubar);
        statusbar = new QStatusBar(hanoiTowers);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        hanoiTowers->setStatusBar(statusbar);

        retranslateUi(hanoiTowers);

        QMetaObject::connectSlotsByName(hanoiTowers);
    } // setupUi

    void retranslateUi(QMainWindow *hanoiTowers)
    {
        hanoiTowers->setWindowTitle(QCoreApplication::translate("hanoiTowers", "hanoiTowers", nullptr));
        T1T2->setText(QCoreApplication::translate("hanoiTowers", "->", nullptr));
        T1T3->setText(QCoreApplication::translate("hanoiTowers", "<-", nullptr));
        T2T3->setText(QCoreApplication::translate("hanoiTowers", "->", nullptr));
        T2T1->setText(QCoreApplication::translate("hanoiTowers", "<-", nullptr));
        T3T1->setText(QCoreApplication::translate("hanoiTowers", "->", nullptr));
        T3T2->setText(QCoreApplication::translate("hanoiTowers", "<-", nullptr));
        restartBtn->setText(QCoreApplication::translate("hanoiTowers", "Restart", nullptr));
        exitBtn->setText(QCoreApplication::translate("hanoiTowers", "EXIT", nullptr));
        T1label->setText(QCoreApplication::translate("hanoiTowers", "TextLabel", nullptr));
        T2label->setText(QCoreApplication::translate("hanoiTowers", "TextLabel", nullptr));
        T3label->setText(QCoreApplication::translate("hanoiTowers", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hanoiTowers: public Ui_hanoiTowers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANOITOWERS_H
