/********************************************************************************
** Form generated from reading UI file 'cockpitscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COCKPITSCREEN_H
#define UI_COCKPITSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CockpitScreen
{
public:
    QSlider *SteeringWheel;
    QLabel *Steering;
    QSlider *BreakPedal;
    QSlider *AcceleratorPedal;
    QLabel *Break_2;
    QLabel *Accelerator;
    QSlider *ReverseSwitch;
    QLabel *Reverse;
    QLabel *BrakeBalance;
    QPushButton *TSActive;
    QPushButton *DriveActive;
    QDial *CruiseDial;
    QLabel *CruiseControl;
    QDial *BalanceDial;
    QDial *ModeDial;
    QLabel *Drivemode;
    QFrame *TSLight;
    QFrame *DriveLight;
    QFrame *ErrorLight;
    QLabel *TS;
    QLabel *label;
    QLabel *label_2;
    QCheckBox *EpuckSteering;
    QPushButton *Run;
    QPushButton *Init;
    QPushButton *pushButton;

    void setupUi(QWidget *CockpitScreen)
    {
        if (CockpitScreen->objectName().isEmpty())
            CockpitScreen->setObjectName(QStringLiteral("CockpitScreen"));
        CockpitScreen->resize(400, 357);
        SteeringWheel = new QSlider(CockpitScreen);
        SteeringWheel->setObjectName(QStringLiteral("SteeringWheel"));
        SteeringWheel->setEnabled(true);
        SteeringWheel->setGeometry(QRect(20, 40, 160, 22));
        SteeringWheel->setValue(50);
        SteeringWheel->setSliderPosition(50);
        SteeringWheel->setOrientation(Qt::Horizontal);
        Steering = new QLabel(CockpitScreen);
        Steering->setObjectName(QStringLiteral("Steering"));
        Steering->setGeometry(QRect(70, 20, 81, 16));
        BreakPedal = new QSlider(CockpitScreen);
        BreakPedal->setObjectName(QStringLiteral("BreakPedal"));
        BreakPedal->setGeometry(QRect(50, 100, 22, 160));
        BreakPedal->setOrientation(Qt::Vertical);
        AcceleratorPedal = new QSlider(CockpitScreen);
        AcceleratorPedal->setObjectName(QStringLiteral("AcceleratorPedal"));
        AcceleratorPedal->setGeometry(QRect(140, 100, 22, 160));
        AcceleratorPedal->setOrientation(Qt::Vertical);
        Break_2 = new QLabel(CockpitScreen);
        Break_2->setObjectName(QStringLiteral("Break_2"));
        Break_2->setGeometry(QRect(30, 80, 61, 20));
        Accelerator = new QLabel(CockpitScreen);
        Accelerator->setObjectName(QStringLiteral("Accelerator"));
        Accelerator->setGeometry(QRect(110, 80, 91, 16));
        ReverseSwitch = new QSlider(CockpitScreen);
        ReverseSwitch->setObjectName(QStringLiteral("ReverseSwitch"));
        ReverseSwitch->setGeometry(QRect(300, 40, 31, 22));
        ReverseSwitch->setMaximum(1);
        ReverseSwitch->setOrientation(Qt::Horizontal);
        Reverse = new QLabel(CockpitScreen);
        Reverse->setObjectName(QStringLiteral("Reverse"));
        Reverse->setGeometry(QRect(286, 20, 71, 20));
        BrakeBalance = new QLabel(CockpitScreen);
        BrakeBalance->setObjectName(QStringLiteral("BrakeBalance"));
        BrakeBalance->setGeometry(QRect(280, 200, 71, 16));
        TSActive = new QPushButton(CockpitScreen);
        TSActive->setObjectName(QStringLiteral("TSActive"));
        TSActive->setGeometry(QRect(280, 70, 75, 23));
        DriveActive = new QPushButton(CockpitScreen);
        DriveActive->setObjectName(QStringLiteral("DriveActive"));
        DriveActive->setGeometry(QRect(280, 100, 75, 23));
        CruiseDial = new QDial(CockpitScreen);
        CruiseDial->setObjectName(QStringLiteral("CruiseDial"));
        CruiseDial->setGeometry(QRect(290, 150, 50, 51));
        CruiseControl = new QLabel(CockpitScreen);
        CruiseControl->setObjectName(QStringLiteral("CruiseControl"));
        CruiseControl->setGeometry(QRect(280, 130, 81, 16));
        BalanceDial = new QDial(CockpitScreen);
        BalanceDial->setObjectName(QStringLiteral("BalanceDial"));
        BalanceDial->setGeometry(QRect(290, 220, 50, 51));
        ModeDial = new QDial(CockpitScreen);
        ModeDial->setObjectName(QStringLiteral("ModeDial"));
        ModeDial->setGeometry(QRect(290, 280, 50, 51));
        ModeDial->setMaximum(5);
        Drivemode = new QLabel(CockpitScreen);
        Drivemode->setObjectName(QStringLiteral("Drivemode"));
        Drivemode->setGeometry(QRect(290, 270, 61, 16));
        TSLight = new QFrame(CockpitScreen);
        TSLight->setObjectName(QStringLiteral("TSLight"));
        TSLight->setGeometry(QRect(50, 300, 16, 16));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 255, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(127, 255, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(63, 255, 63, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(0, 127, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(0, 170, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        TSLight->setPalette(palette);
        TSLight->setLineWidth(0);
        TSLight->setMidLineWidth(16);
        TSLight->setFrameShape(QFrame::VLine);
        TSLight->setFrameShadow(QFrame::Sunken);
        DriveLight = new QFrame(CockpitScreen);
        DriveLight->setObjectName(QStringLiteral("DriveLight"));
        DriveLight->setGeometry(QRect(110, 300, 16, 16));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        DriveLight->setPalette(palette1);
        DriveLight->setLineWidth(0);
        DriveLight->setMidLineWidth(16);
        DriveLight->setFrameShape(QFrame::VLine);
        DriveLight->setFrameShadow(QFrame::Sunken);
        ErrorLight = new QFrame(CockpitScreen);
        ErrorLight->setObjectName(QStringLiteral("ErrorLight"));
        ErrorLight->setGeometry(QRect(160, 300, 16, 16));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        ErrorLight->setPalette(palette2);
        ErrorLight->setLineWidth(0);
        ErrorLight->setMidLineWidth(16);
        ErrorLight->setFrameShape(QFrame::VLine);
        ErrorLight->setFrameShadow(QFrame::Sunken);
        TS = new QLabel(CockpitScreen);
        TS->setObjectName(QStringLiteral("TS"));
        TS->setGeometry(QRect(50, 280, 21, 16));
        label = new QLabel(CockpitScreen);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 280, 31, 16));
        label_2 = new QLabel(CockpitScreen);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 280, 31, 16));
        EpuckSteering = new QCheckBox(CockpitScreen);
        EpuckSteering->setObjectName(QStringLiteral("EpuckSteering"));
        EpuckSteering->setGeometry(QRect(190, 40, 70, 17));
        Run = new QPushButton(CockpitScreen);
        Run->setObjectName(QStringLiteral("Run"));
        Run->setGeometry(QRect(50, 330, 75, 23));
        Init = new QPushButton(CockpitScreen);
        Init->setObjectName(QStringLiteral("Init"));
        Init->setGeometry(QRect(150, 330, 75, 23));
        pushButton = new QPushButton(CockpitScreen);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 330, 75, 23));

        retranslateUi(CockpitScreen);
        QObject::connect(SteeringWheel, SIGNAL(valueChanged(int)), CockpitScreen, SLOT(steering_cb(int)));
        QObject::connect(BreakPedal, SIGNAL(valueChanged(int)), CockpitScreen, SLOT(break_cb(int)));
        QObject::connect(AcceleratorPedal, SIGNAL(valueChanged(int)), CockpitScreen, SLOT(accelerator_cb(int)));
        QObject::connect(CruiseDial, SIGNAL(valueChanged(int)), CockpitScreen, SLOT(cruise_cb(int)));
        QObject::connect(BalanceDial, SIGNAL(valueChanged(int)), CockpitScreen, SLOT(breakBalance_cb(int)));
        QObject::connect(TSActive, SIGNAL(released()), CockpitScreen, SLOT(TS_cb()));
        QObject::connect(DriveActive, SIGNAL(released()), CockpitScreen, SLOT(drive_cb()));
        QObject::connect(EpuckSteering, SIGNAL(stateChanged(int)), CockpitScreen, SLOT(useEpuck(int)));
        QObject::connect(Init, SIGNAL(released()), CockpitScreen, SLOT(restart()));
        QObject::connect(Run, SIGNAL(released()), CockpitScreen, SLOT(startStop()));
        QObject::connect(ModeDial, SIGNAL(valueChanged(int)), CockpitScreen, SLOT(driveMode_cb(int)));
        QObject::connect(pushButton, SIGNAL(released()), CockpitScreen, SLOT(quit_cb()));

        QMetaObject::connectSlotsByName(CockpitScreen);
    } // setupUi

    void retranslateUi(QWidget *CockpitScreen)
    {
        CockpitScreen->setWindowTitle(QApplication::translate("CockpitScreen", "Cockpit", 0));
        Steering->setText(QApplication::translate("CockpitScreen", "Steering Wheel", 0));
        Break_2->setText(QApplication::translate("CockpitScreen", "Break Pedal", 0));
        Accelerator->setText(QApplication::translate("CockpitScreen", "Accelerator Pedal", 0));
        Reverse->setText(QApplication::translate("CockpitScreen", "Reverse Switch", 0));
        BrakeBalance->setText(QApplication::translate("CockpitScreen", "Brake Balance", 0));
        TSActive->setText(QApplication::translate("CockpitScreen", "TS", 0));
        DriveActive->setText(QApplication::translate("CockpitScreen", "Drive", 0));
        CruiseControl->setText(QApplication::translate("CockpitScreen", "Cruise Control", 0));
        Drivemode->setText(QApplication::translate("CockpitScreen", "Drivemode", 0));
        TS->setText(QApplication::translate("CockpitScreen", "TS", 0));
        label->setText(QApplication::translate("CockpitScreen", "Drive", 0));
        label_2->setText(QApplication::translate("CockpitScreen", "Error", 0));
        EpuckSteering->setText(QApplication::translate("CockpitScreen", "use Epuck", 0));
        Run->setText(QApplication::translate("CockpitScreen", "Run", 0));
        Init->setText(QApplication::translate("CockpitScreen", "Init", 0));
        pushButton->setText(QApplication::translate("CockpitScreen", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class CockpitScreen: public Ui_CockpitScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COCKPITSCREEN_H
