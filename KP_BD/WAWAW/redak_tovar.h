#ifndef REDAK_TOVAR_H
#define REDAK_TOVAR_H

#include <QDialog>
#include <QSqlQuery>
#include<QSqlTableModel>
#include<QString>
#include <QtCore>
#include <QSqlQueryModel>
#include <QMainWindow>

namespace Ui {
class redak_tovar;
}

class redak_tovar : public QMainWindow
{
    Q_OBJECT

public:
    explicit redak_tovar(QWidget *parent = nullptr);
    ~redak_tovar();

private slots:
    void on_redak_clicked();

private:
    Ui::redak_tovar *ui;
    QSqlDatabase database;
    QSqlQuery *qry;
    QSqlTableModel *model;
};

#endif // REDAK_TOVAR_H
