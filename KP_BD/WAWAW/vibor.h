#ifndef VIBOR_H
#define VIBOR_H
#include "tovar.h"
#include "sklad.h"
#include "sold.h"
#include "buy.h"
#include <QDialog>
#include"../qq/qq.h"
namespace Ui {
class vibor;
}

class vibor : public QDialog
{
    Q_OBJECT

public:
    explicit vibor(QWidget *parent = nullptr);
    ~vibor();

private slots:
    void on_sklad_clicked();
    void on_tovar_clicked();
    void on_sold_clicked();
    void on_buy_clicked();

private:
    Ui::vibor *ui;
    sklad *window;
    tovar *window1;
    Sold *window2;
    buy *window3;
};

#endif // VIBOR_H
