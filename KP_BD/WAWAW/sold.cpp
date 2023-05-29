#include "sold.h"
#include "ui_sold.h"
#include <QMessageBox>
#include <QDebug>
#include"../qq/qq.h"
#include<QTableView>
#include"sprpolzovat.h"
Sold::Sold(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sold)
{
    ui->setupUi(this);
    window1=new save_sold;
    window2=new redak_sold;
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/portl/OneDrive/Desktop/kyrs/WAWAW/TestDDB.db");
    if (db.open())
        qDebug("База данных открыта");
    else
        qDebug("Ошибка. База данных не открыта");
    query = new QSqlQuery(db);
    model = new QSqlTableModel(this,db);
    model -> setTable("Продажа");
    model ->select();
    ui ->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
}

Sold::~Sold()
{
    delete ui;
}
void Sold::on_sprav_clicked()
{
    window = new SPRPOLZOVAT(this);
    window -> show();
}
void Sold::on_udalen_clicked()
{
    ui->statusbar->showMessage("Удаление позиции...");
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Удаление позиции.","Вы уверены, что хотите удалить позицию?");
    if(reply == QMessageBox::Yes)
    {
    model->removeRow(row); //УДАЛЕНИЕ СТРОКИ ПО НО ЕЕ НОМЕРУ
    }

    else
        qDebug("/q");
    ui->statusbar->showMessage(" ");
}

void Sold::on_dopol_clicked()
{
    window1 ->show();
}
void Sold::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

void Sold::on_vihod_clicked()
{
    ui->statusbar->showMessage("Выход из приложения...");
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Выход из приложения.","Вы уверены, что хотите выйти из приложения?");
    if(reply == QMessageBox::Yes)
{   Qq o;
    o.clos();
}
    else
        qDebug("/q");
    ui->statusbar->showMessage(" ");
}

void Sold::on_obnov_clicked()
{
    QString id;
    QSqlQuery qry;
    qry.prepare("select * from Продажа");
    model = new QSqlTableModel(this,db);
    model->setTable("Продажа");
    model->select();
    ui->tableView->setModel(model);
}

void Sold::on_poisk_clicked()
{

char percent = '%';
QSqlQuery query;

QString querySearchString = QString("ID_продажи LIKE '%1%2' OR Дата LIKE '%1%2' OR Стоимость LIKE '%1%2' OR Название_товара LIKE '%1%2' OR Количество LIKE '%1%2'")
.arg(ui->poiskS->text()).arg(percent);



this->model->setFilter(querySearchString);
this->model->select();
this->ui->tableView->update();


}

void Sold::on_redak_clicked()
{
    window2->show();

}
