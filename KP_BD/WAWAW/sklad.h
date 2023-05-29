#ifndef SKLAD_H
#define SKLAD_H
#include"sprpolzovat.h"
#include"save_sklad.h"
#include"redak_sklad.h"
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
class sklad;
}
QT_END_NAMESPACE

class sklad : public QMainWindow
{
    Q_OBJECT

public:
    explicit sklad(QWidget *parent = nullptr);
    ~sklad();
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
    Ui::sklad *ui;
    SPRPOLZOVAT *window;
    int row; //НОМЕР СТРОКИ ТАБЛИЦЫ
    //QStandardItemModel *model;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    Qq *o;
    Qq *p;
    save_sklad *window1;
    redak_sklad *window2;
};

#endif // SKLAD_H
