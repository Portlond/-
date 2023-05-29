#include "save_tovar.h"
#include "ui_save_tovar.h"
#include <QMessageBox>
#include <QDebug>
#include<QTableView>
#include <QSqlError>

save_tovar::save_tovar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::save_tovar)
{
    ui->setupUi(this);
    database= QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/portl/OneDrive/Desktop/kyrs/WAWAW/TestDDB.db");
}

save_tovar::~save_tovar()
{
    delete ui;
}

void save_tovar::on_save_clicked()
{
    QString nazvanie,id_tovara;
    nazvanie=ui->lineEdit->text();
    id_tovara=ui->lineEdit_2->text();
    QSqlQuery qry;
    qry.prepare("INSERT INTO Товар (Название_товара,ID_товара) "
                "VALUES (:nazvanie, :id_tovara)");
    qry.bindValue(":nazvanie", nazvanie);
    qry.bindValue(":id_tovara", id_tovara);
 if(qry.exec()){
 QMessageBox::information(this,"База_данных","Сохранено");
 } else{
 QMessageBox::critical(this,"База_данных",qry.lastError().text());}
}
