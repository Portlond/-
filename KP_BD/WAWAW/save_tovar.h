#ifndef SAVE_TOVAR_H
#define SAVE_TOVAR_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QSqlTableModel>
#include<QString>
#include <QtCore>
#include <QSqlQueryModel>
#include <QMainWindow>

namespace Ui {
class save_tovar;
}

class save_tovar : public QMainWindow
{
    Q_OBJECT

public:
    explicit save_tovar(QWidget *parent = nullptr);
    ~save_tovar();

private slots:
    void on_save_clicked();

private:
    Ui::save_tovar *ui;
    QSqlDatabase database;
    QSqlQuery *qry;
    QSqlTableModel *model;
    QSqlQueryModel *model1;
};

#endif // SAVE_TOVAR_H
