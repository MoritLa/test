#include "cockpitscreen.h"
#include "ui_cockpitscreen.h"

CockpitScreen::CockpitScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CockpitScreen)
{
    ui->setupUi(this);
}

CockpitScreen::~CockpitScreen()
{
    delete ui;
}
