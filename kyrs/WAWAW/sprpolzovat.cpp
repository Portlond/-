#include "sprpolzovat.h"
#include "ui_sprpolzovat.h"

SPRPOLZOVAT::SPRPOLZOVAT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SPRPOLZOVAT)
{
    ui->setupUi(this);
}

SPRPOLZOVAT::~SPRPOLZOVAT()
{
    delete ui;
}



