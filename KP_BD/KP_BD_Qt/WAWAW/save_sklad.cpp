#include "save_sklad.h"
#include "ui_save_sklad.h"
#include <QMessageBox>
#include <QDebug>
#include<QTableView>
#include <QSqlError>
#include <QComboBox>

save_sklad::save_sklad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::save_sklad)
{
    ui->setupUi(this);
    database= QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/portl/OneDrive/Desktop/kyrs/WAWAW/TestDDB.db");
    database.open();
    this->nazvanie();
}

save_sklad::~save_sklad()
{
    delete ui;
}

void save_sklad::nazvanie()
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

void save_sklad::on_save_clicked()
{
    QString id_sektora,nazvanie,kol_tovara;
    id_sektora=ui->lineEdit->text();
    nazvanie=ui->comboBox->currentText();
    kol_tovara=ui->lineEdit_3->text();
    QSqlQuery qry;
    qry.prepare("INSERT INTO Склад (ID_сектора,Название_товара,Количество) "
                "VALUES (:id_sektora, :nazvanie, :kol_tovara)");
    qry.bindValue(":id_sektora", id_sektora);
    qry.bindValue(":nazvanie", nazvanie);
    qry.bindValue(":kol_tovara", kol_tovara);
 if(qry.exec()){
 QMessageBox::information(this,"База_данных","Сохранено");
 } else{
 QMessageBox::critical(this,"База_данных",qry.lastError().text());}
}
