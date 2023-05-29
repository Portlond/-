#ifndef SAVE_SOLD_H
#define SAVE_SOLD_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QSqlTableModel>
#include<QString>
#include <QtCore>
#include <QSqlQueryModel>
#include <QMainWindow>
#include <QComboBox>

namespace Ui {
class save_sold;
}

class save_sold : public QMainWindow
{
    Q_OBJECT

public:
    explicit save_sold(QWidget *parent = nullptr);
    ~save_sold();

private slots:
    void on_save_clicked();
    void nazvanie();

private:
    Ui::save_sold *ui;
    QSqlDatabase database;
    QSqlQuery *qry;
    QSqlTableModel *model;
    QSqlQueryModel *model1;
};

#endif // SAVE_SOLD_H
