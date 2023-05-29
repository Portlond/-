#include "vibor.h"
#include "ui_vibor.h"
#include "tovar.h"
#include "sklad.h"
#include "sold.h"
#include "buy.h"
#include"../qq/qq.h"
vibor::vibor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vibor)
{
    ui->setupUi(this);
}

vibor::~vibor()
{
    delete ui;
}

void vibor::on_sklad_clicked()
{
    window = new sklad(this);
    window -> show();
}

void vibor::on_tovar_clicked()
{
    window1 = new tovar(this);
    window1 -> show();
}

void vibor::on_sold_clicked()
{
    window2 = new Sold(this);
    window2 -> show();
}
void vibor::on_buy_clicked()
{
    window3 = new buy(this);
    window3 -> show();
}
