#include "save_sold.h"
#include "ui_save_sold.h"
#include <QMessageBox>
#include <QDebug>
#include<QTableView>
#include <QSqlError>
#include <QComboBox>
#include <QDateEdit>

save_sold::save_sold(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::save_sold)
{
    ui->setupUi(this);
    database= QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/portl/OneDrive/Desktop/kyrs/WAWAW/TestDDB.db");
    database.open();
    this->nazvanie();
}

save_sold::~save_sold()
{
    delete ui;
}

void save_sold::nazvanie()
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

void save_sold::on_save_clicked()
{
    QString id_prodazhi,data_prodazhi,stoim_prodazhi,nazvanie,kol_tovara;
    id_prodazhi=ui->lineEdit->text();
    data_prodazhi=ui->dateEdit->text();
    stoim_prodazhi=ui->lineEdit_3->text();
    nazvanie=ui->comboBox->currentText();
    kol_tovara=ui->lineEdit_5->text();
    QSqlQuery qry;
    qry.prepare("INSERT INTO Продажа (ID_продажи,Дата,Стоимость,Название_товара,Количество) "
                "VALUES (:id_prodazhi, :data_prodazhi, :stoim_prodazhi, :nazvanie, :kol_tovara)");
    qry.bindValue(":id_prodazhi", id_prodazhi);
    qry.bindValue(":data_prodazhi", data_prodazhi);
    qry.bindValue(":stoim_prodazhi", stoim_prodazhi);
    qry.bindValue(":nazvanie", nazvanie);
    qry.bindValue(":kol_tovara", kol_tovara);
 if(qry.exec()){
 QMessageBox::information(this,"База_данных","Сохранено");
 } else{
 QMessageBox::critical(this,"База_данных",qry.lastError().text());}
}
