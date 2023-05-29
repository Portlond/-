#include "redak_tovar.h"
#include "ui_redak_tovar.h"
#include <QMessageBox>
#include <QDebug>
#include<QTableView>
#include <QSqlError>

redak_tovar::redak_tovar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::redak_tovar)
{
    ui->setupUi(this);
    database= QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/portl/OneDrive/Desktop/kyrs/WAWAW/TestDDB.db");
}

redak_tovar::~redak_tovar()
{
    delete ui;
}

void redak_tovar::on_redak_clicked()
{
    QString nazvanie,id_tovara;
    nazvanie=ui->lineEdit->text();
    id_tovara=ui->lineEdit_2->text();
    QSqlQuery qry;
    qry.prepare("UPDATE  Товар set Название_товара=:nazvanie, ID_товара=:id_tovara WHERE Название_товара=:nazvanie" );
    qry.bindValue(":nazvanie", nazvanie);
    qry.bindValue(":id_tovara", id_tovara);

    if(qry.exec()){
    QMessageBox::information(this,"База_данных","Изменено");
    } else{
    QMessageBox::critical(this,"База_данных",qry.lastError().text());
    }

}
