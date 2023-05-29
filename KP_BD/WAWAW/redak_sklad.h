#ifndef REDAK_SKLAD_H
#define REDAK_SKLAD_H

#include <QDialog>
#include <QSqlQuery>
#include<QSqlTableModel>
#include<QString>
#include <QtCore>
#include <QSqlQueryModel>
#include <QMainWindow>
#include <QComboBox>

namespace Ui {
class redak_sklad;
}

class redak_sklad : public QMainWindow
{
    Q_OBJECT

public:
    explicit redak_sklad(QWidget *parent = nullptr);
    ~redak_sklad();

private slots:
    void on_redak_clicked();
    void nazvanie();

private:
    Ui::redak_sklad *ui;
    QSqlDatabase database;
    QSqlQuery *qry;
    QSqlTableModel *model;
};

#endif // REDAK_SKLAD_H
