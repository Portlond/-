#ifndef SOLD_H
#define SOLD_H
#include"sprpolzovat.h"
#include"save_sold.h"
#include"redak_sold.h"
#include <QMainWindow>
#include <QDialog>
#include<QString>
#include <QtCore>
#include <QtGui>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include<QSqlTableModel>
#include"../qq/qq.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Sold;
}
QT_END_NAMESPACE

class Sold : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sold(QWidget *parent = nullptr);
    ~Sold();
private slots:
    void on_sprav_clicked();
    void on_udalen_clicked();
    void on_dopol_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_vihod_clicked();
    void on_obnov_clicked();
    void on_poisk_clicked();
    void on_redak_clicked();

private:
    Ui::Sold *ui;
    SPRPOLZOVAT *window;
    int row; //НОМЕР СТРОКИ ТАБЛИЦЫ
    //QStandardItemModel *model;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    Qq *o;
    Qq *p;
    save_sold *window1;
    redak_sold *window2;
};

#endif // SOLD_H
