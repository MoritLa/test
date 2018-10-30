#include "infoscreen.h"
#include "ui_infoscreen.h"

infoScreen::infoScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::infoScreen)
{
    ui->setupUi(this);

//  set list title
    ui->VSI->setText("VSI") ;
    ui->batterie->setText(("Batterie")) ;
    ui->wheel_fl->setText("front left") ;
    ui->wheel_fr->setText("front right") ;
    ui->wheel_rl->setText("rear left") ;
    ui->wheel_rr->setText("rear right") ;
}

infoScreen::~infoScreen()
{
    delete ui;
}

