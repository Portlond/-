#ifndef TOVAR_H
#define TOVAR_H
#include"sprpolzovat.h"
#include"save_tovar.h"
#include"redak_tovar.h"
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
namespace Ui {
class tovar;
}

class tovar : public QMainWindow
{
    Q_OBJECT

public:
    explicit tovar(QWidget *parent = nullptr);
    ~tovar();
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
    Ui::tovar *ui;
    SPRPOLZOVAT *window;
    int row; //НОМЕР СТРОКИ ТАБЛИЦЫ
    //QStandardItemModel *model;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    Qq *o;
    Qq *p;
    save_tovar *window1;
    redak_tovar *window2;
};

#endif // TOVAR_H
