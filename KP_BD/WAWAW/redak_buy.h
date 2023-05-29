#ifndef REDAK_BUY_H
#define REDAK_BUY_H

#include <QDialog>
#include <QSqlQuery>
#include<QSqlTableModel>
#include<QString>
#include <QtCore>
#include <QSqlQueryModel>
#include <QMainWindow>
#include <QComboBox>

namespace Ui {
class redak_buy;
}

class redak_buy : public QMainWindow
{
    Q_OBJECT

public:
    explicit redak_buy(QWidget *parent = nullptr);
    ~redak_buy();

private slots:
    void on_redak_clicked();
    void nazvanie();

private:
    Ui::redak_buy *ui;
    QSqlDatabase database;
    QSqlQuery *qry;
    QSqlTableModel *model;

signals:
    void obnov();

public slots:
    void obnov_redak();


};

#endif // REDAK_BUY_H
