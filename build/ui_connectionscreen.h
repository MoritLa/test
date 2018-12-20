/********************************************************************************
** Form generated from reading UI file 'connectionscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONSCREEN_H
#define UI_CONNECTIONSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectionScreen
{
public:
    QPushButton *ConnectMotor;
    QLineEdit *MotorPort;
    QLabel *Motor;
    QLabel *Sensor;
    QLineEdit *SensorPort;
    QPushButton *ConnectSensor;
    QPushButton *ConnectECU;
    QLineEdit *ECUPort;
    QLabel *ECU;

    void setupUi(QWidget *ConnectionScreen)
    {
        if (ConnectionScreen->objectName().isEmpty())
            ConnectionScreen->setObjectName(QStringLiteral("ConnectionScreen"));
        ConnectionScreen->resize(291, 124);
        ConnectMotor = new QPushButton(ConnectionScreen);
        ConnectMotor->setObjectName(QStringLiteral("ConnectMotor"));
        ConnectMotor->setGeometry(QRect(190, 20, 75, 23));
        MotorPort = new QLineEdit(ConnectionScreen);
        MotorPort->setObjectName(QStringLiteral("MotorPort"));
        MotorPort->setGeometry(QRect(70, 20, 113, 20));
        Motor = new QLabel(ConnectionScreen);
        Motor->setObjectName(QStringLiteral("Motor"));
        Motor->setGeometry(QRect(20, 20, 41, 16));
        Sensor = new QLabel(ConnectionScreen);
        Sensor->setObjectName(QStringLiteral("Sensor"));
        Sensor->setGeometry(QRect(20, 50, 41, 16));
        SensorPort = new QLineEdit(ConnectionScreen);
        SensorPort->setObjectName(QStringLiteral("SensorPort"));
        SensorPort->setGeometry(QRect(70, 50, 113, 20));
        ConnectSensor = new QPushButton(ConnectionScreen);
        ConnectSensor->setObjectName(QStringLiteral("ConnectSensor"));
        ConnectSensor->setGeometry(QRect(190, 50, 75, 23));
        ConnectECU = new QPushButton(ConnectionScreen);
        ConnectECU->setObjectName(QStringLiteral("ConnectECU"));
        ConnectECU->setGeometry(QRect(190, 80, 75, 23));
        ECUPort = new QLineEdit(ConnectionScreen);
        ECUPort->setObjectName(QStringLiteral("ECUPort"));
        ECUPort->setGeometry(QRect(70, 80, 113, 20));
        ECU = new QLabel(ConnectionScreen);
        ECU->setObjectName(QStringLiteral("ECU"));
        ECU->setGeometry(QRect(20, 80, 41, 16));

        retranslateUi(ConnectionScreen);
        QObject::connect(ConnectMotor, SIGNAL(released()), ConnectionScreen, SLOT(motor_cb()));
        QObject::connect(ConnectSensor, SIGNAL(released()), ConnectionScreen, SLOT(sensor_cb()));
        QObject::connect(ConnectECU, SIGNAL(released()), ConnectionScreen, SLOT(ECU_cb()));
        QObject::connect(MotorPort, SIGNAL(returnPressed()), ConnectionScreen, SLOT(motor_cb()));
        QObject::connect(SensorPort, SIGNAL(returnPressed()), ConnectionScreen, SLOT(sensor_cb()));
        QObject::connect(ECUPort, SIGNAL(returnPressed()), ConnectionScreen, SLOT(ECU_cb()));

        QMetaObject::connectSlotsByName(ConnectionScreen);
    } // setupUi

    void retranslateUi(QWidget *ConnectionScreen)
    {
        ConnectionScreen->setWindowTitle(QApplication::translate("ConnectionScreen", "Connection", 0));
        ConnectMotor->setText(QApplication::translate("ConnectionScreen", "Connect", 0));
        MotorPort->setText(QApplication::translate("ConnectionScreen", "COM9", 0));
        Motor->setText(QApplication::translate("ConnectionScreen", "Motor:", 0));
        Sensor->setText(QApplication::translate("ConnectionScreen", "Sensors:", 0));
        SensorPort->setText(QApplication::translate("ConnectionScreen", "COM31", 0));
        ConnectSensor->setText(QApplication::translate("ConnectionScreen", "Connect", 0));
        ConnectECU->setText(QApplication::translate("ConnectionScreen", "Connect", 0));
        ECUPort->setText(QApplication::translate("ConnectionScreen", "COM24", 0));
        ECU->setText(QApplication::translate("ConnectionScreen", "ECU:", 0));
    } // retranslateUi

};

namespace Ui {
    class ConnectionScreen: public Ui_ConnectionScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONSCREEN_H
