#include "redak_buy.h"
#include "ui_redak_buy.h"
#include <QMessageBox>
#include <QDebug>
#include<QTableView>
#include <QSqlError>
#include <QComboBox>
#include <QDateEdit>

redak_buy::redak_buy(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::redak_buy)
{
    ui->setupUi(this);
    database= QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/portl/OneDrive/Desktop/kyrs/WAWAW/TestDDB.db");
    database.open();
    this->nazvanie();
    this->obnov_redak();
}

redak_buy::~redak_buy()
{
    delete ui;
}

void redak_buy::nazvanie()
{
    QSqlQuery query;
    if (!query.exec("SELECT COUNT(*) FROM Товар"))
    {
        qDebug() << "Вызов не работает";
        qDebug() << query.lastError().text();
        qDebug() << query.lastQuery();
    }

    query.next();
    QSqlQuery queryGetCompany;
    if (!queryGetCompany.exec("SELECT Название_товара FROM Товар"))
    {
        qDebug() << "Вызов не работает";
        qDebug() << queryGetCompany.lastError().text();
        qDebug() << queryGetCompany.lastQuery();
    }
    for(int i = 0; i < query.value(0).toInt(); i++)
    {
        queryGetCompany.next();
        ui->comboBox->addItem(queryGetCompany.value(0).toString());
    }

}

void redak_buy::obnov_redak()
{
    emit obnov();
}

void redak_buy::on_redak_clicked()
{
    QString id_zakupki,data_zakupki,stoim_zakupki,nazvanie,kol_tovara;
    id_zakupki=ui->lineEdit->text();
    data_zakupki=ui->dateEdit->text();
    stoim_zakupki=ui->lineEdit_3->text();
    nazvanie=ui->comboBox->currentText();
    kol_tovara=ui->lineEdit_5->text();
    QSqlQuery qry;
    qry.prepare("UPDATE  Закупка set ID_закупки=:id_zakupki, Дата=:data_zakupki, Стоимость=:stoim_zakupki, "
                "Название_товара=:nazvanie, Количество=:kol_tovara"
                " WHERE ID_закупки=:id_zakupki" );
    qry.bindValue(":id_zakupki", id_zakupki);
    qry.bindValue(":data_zakupki", data_zakupki);
    qry.bindValue(":stoim_zakupki", stoim_zakupki);
    qry.bindValue(":nazvanie", nazvanie);
    qry.bindValue(":kol_tovara", kol_tovara);

    if(qry.exec()){
    QMessageBox::information(this,"База_данных","Изменено");
    } else{
    QMessageBox::critical(this,"База_данных",qry.lastError().text());
    }

}
