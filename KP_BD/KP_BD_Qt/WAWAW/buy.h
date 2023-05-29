#ifndef BUY_H
#define BUY_H
#include"sprpolzovat.h"
#include"save_buy.h"
#include"redak_buy.h"
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
class buy;
}

class buy : public QMainWindow
{
    Q_OBJECT

public:
    explicit buy(QWidget *parent = nullptr);
    ~buy();
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
    Ui::buy *ui;
    SPRPOLZOVAT *window;
    int row; //НОМЕР СТРОКИ ТАБЛИЦЫ
    //QStandardItemModel *model;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    Qq *o;
    Qq *p;
    save_buy *window1;
    redak_buy *window2;

public slots:
        void obnov();
};

#endif // BUY_H
