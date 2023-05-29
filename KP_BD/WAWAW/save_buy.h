#ifndef SAVE_BUY_H
#define SAVE_BUY_H

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
class save_buy;
}

class save_buy : public QMainWindow
{
    Q_OBJECT

public:
    explicit save_buy(QWidget *parent = nullptr);
    ~save_buy();

private slots:
    void on_save_clicked();
    void nazvanie();

private:
    Ui::save_buy *ui;
    QSqlDatabase database;
    QSqlQuery *qry;
    QSqlTableModel *model;
    QSqlQueryModel *model1;
};

#endif // SAVE_BUY_H
