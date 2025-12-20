/********************************************************************************
** Form generated from reading UI file 'cgui.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CGUI_H
#define UI_CGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CGUI
{
public:
    QWidget *centralwidget;
    QTextEdit *teStatus;
    QLabel *label;
    QGroupBox *groupBox;
    QPushButton *pbEtatCFG;
    QLabel *lZoneData;
    QLabel *lZoneConfig;
    QPushButton *pbLireCFG;
    QPushButton *pbEtatDATA;
    QGroupBox *groupBox_2;
    QPushButton *pbVersion;
    QPushButton *pbSerie;
    QGroupBox *groupBox_3;
    QSpinBox *sbSlot;
    QPushButton *pbSlots;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CGUI)
    {
        if (CGUI->objectName().isEmpty())
            CGUI->setObjectName("CGUI");
        CGUI->resize(800, 600);
        centralwidget = new QWidget(CGUI);
        centralwidget->setObjectName("centralwidget");
        teStatus = new QTextEdit(centralwidget);
        teStatus->setObjectName("teStatus");
        teStatus->setGeometry(QRect(10, 170, 731, 361));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 0, 221, 22));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(390, 30, 351, 121));
        pbEtatCFG = new QPushButton(groupBox);
        pbEtatCFG->setObjectName("pbEtatCFG");
        pbEtatCFG->setGeometry(QRect(10, 50, 92, 30));
        lZoneData = new QLabel(groupBox);
        lZoneData->setObjectName("lZoneData");
        lZoneData->setGeometry(QRect(210, 30, 131, 22));
        QFont font;
        font.setBold(true);
        lZoneData->setFont(font);
        lZoneData->setTextFormat(Qt::TextFormat::RichText);
        lZoneConfig = new QLabel(groupBox);
        lZoneConfig->setObjectName("lZoneConfig");
        lZoneConfig->setGeometry(QRect(10, 30, 161, 22));
        lZoneConfig->setFont(font);
        lZoneConfig->setTextFormat(Qt::TextFormat::RichText);
        pbLireCFG = new QPushButton(groupBox);
        pbLireCFG->setObjectName("pbLireCFG");
        pbLireCFG->setGeometry(QRect(10, 80, 92, 30));
        pbEtatDATA = new QPushButton(groupBox);
        pbEtatDATA->setObjectName("pbEtatDATA");
        pbEtatDATA->setGeometry(QRect(210, 50, 92, 30));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 30, 181, 121));
        pbVersion = new QPushButton(groupBox_2);
        pbVersion->setObjectName("pbVersion");
        pbVersion->setGeometry(QRect(20, 40, 92, 30));
        pbSerie = new QPushButton(groupBox_2);
        pbSerie->setObjectName("pbSerie");
        pbSerie->setGeometry(QRect(20, 80, 92, 30));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(200, 30, 181, 121));
        sbSlot = new QSpinBox(groupBox_3);
        sbSlot->setObjectName("sbSlot");
        sbSlot->setGeometry(QRect(20, 30, 47, 31));
        sbSlot->setMaximum(15);
        pbSlots = new QPushButton(groupBox_3);
        pbSlots->setObjectName("pbSlots");
        pbSlots->setGeometry(QRect(70, 30, 92, 30));
        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 70, 92, 30));
        CGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CGUI);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 27));
        CGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(CGUI);
        statusbar->setObjectName("statusbar");
        CGUI->setStatusBar(statusbar);

        retranslateUi(CGUI);

        QMetaObject::connectSlotsByName(CGUI);
    } // setupUi

    void retranslateUi(QMainWindow *CGUI)
    {
        CGUI->setWindowTitle(QCoreApplication::translate("CGUI", "Gestion du ATECC608B (v1.0) by PhA @2025-2026", nullptr));
        label->setText(QCoreApplication::translate("CGUI", "ATECC608B", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CGUI", "Zones", nullptr));
        pbEtatCFG->setText(QCoreApplication::translate("CGUI", "Etat CFG", nullptr));
        lZoneData->setText(QCoreApplication::translate("CGUI", "Zone DATA", nullptr));
        lZoneConfig->setText(QCoreApplication::translate("CGUI", "Zone CONFIG", nullptr));
        pbLireCFG->setText(QCoreApplication::translate("CGUI", "Lire CFG", nullptr));
        pbEtatDATA->setText(QCoreApplication::translate("CGUI", "Etat DATA", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("CGUI", "Init", nullptr));
        pbVersion->setText(QCoreApplication::translate("CGUI", "Version", nullptr));
        pbSerie->setText(QCoreApplication::translate("CGUI", "N\302\260 de s\303\251rie", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("CGUI", "Slots", nullptr));
        pbSlots->setText(QCoreApplication::translate("CGUI", "Slots", nullptr));
        pushButton->setText(QCoreApplication::translate("CGUI", "G\303\251n\303\251rer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CGUI: public Ui_CGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CGUI_H
