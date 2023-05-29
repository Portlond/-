#include "redak_sklad.h"
#include "ui_redak_sklad.h"
#include <QMessageBox>
#include <QDebug>
#include<QTableView>
#include <QSqlError>
#include <QComboBox>


redak_sklad::redak_sklad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::redak_sklad)
{
    ui->setupUi(this);
    database= QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/portl/OneDrive/Desktop/kyrs/WAWAW/TestDDB.db");
    database.open();
    this->nazvanie();
}

redak_sklad::~redak_sklad()
{
    delete ui;
}

void redak_sklad::nazvanie()
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

void redak_sklad::on_redak_clicked()
{
    QString id_sektora,nazvanie,kol_tovara;
    id_sektora=ui->lineEdit->text();
    nazvanie=ui->comboBox->currentText();
    kol_tovara=ui->lineEdit_3->text();
    QSqlQuery qry;
    qry.prepare("UPDATE  Склад set ID_сектора=:id_sektora, Название_товара=:nazvanie, Количество=:kol_tovara WHERE ID_сектора=:id_sektora" );
    qry.bindValue(":id_sektora", id_sektora);
    qry.bindValue(":nazvanie", nazvanie);
    qry.bindValue(":kol_tovara", kol_tovara);

    if(qry.exec()){
    QMessageBox::information(this,"База_данных","Изменено");
    } else{
    QMessageBox::critical(this,"База_данных",qry.lastError().text());
    }

}
