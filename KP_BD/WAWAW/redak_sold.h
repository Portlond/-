#ifndef REDAK_SOLD_H
#define REDAK_SOLD_H

#include <QDialog>
#include <QSqlQuery>
#include<QSqlTableModel>
#include<QString>
#include <QtCore>
#include <QSqlQueryModel>
#include <QMainWindow>
#include <QComboBox>

namespace Ui {
class redak_sold;
}

class redak_sold : public QMainWindow
{
    Q_OBJECT

public:
    explicit redak_sold(QWidget *parent = nullptr);
    ~redak_sold();

private slots:
    void on_redak_clicked();
    void nazvanie();

private:
    Ui::redak_sold *ui;
    QSqlDatabase database;
    QSqlQuery *qry;
    QSqlTableModel *model;
};

#endif // REDAK_SOLD_H
