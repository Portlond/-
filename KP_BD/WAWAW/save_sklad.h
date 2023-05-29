#ifndef SAVE_SKLAD_H
#define SAVE_SKLAD_H

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
class save_sklad;
}

class save_sklad : public QMainWindow
{
    Q_OBJECT

public:
    explicit save_sklad(QWidget *parent = nullptr);
    ~save_sklad();

private slots:
    void on_save_clicked();
    void nazvanie();

private:
    Ui::save_sklad *ui;
    QSqlDatabase database;
    QSqlQuery *qry;
    QSqlTableModel *model;
    QSqlQueryModel *model1;
};

#endif // SAVE_SKLAD_H
