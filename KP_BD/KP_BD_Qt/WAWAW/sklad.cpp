#include "sklad.h"
#include "ui_sklad.h"
#include <QMessageBox>
#include <QDebug>
#include"../qq/qq.h"
#include<QTableView>
#include"sprpolzovat.h"
sklad::sklad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sklad)
{
    ui->setupUi(this);
    window1=new save_sklad;
    window2=new redak_sklad;
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/portl/OneDrive/Desktop/kyrs/WAWAW/TestDDB.db");
    if (db.open())
        qDebug("База данных открыта");
    else
        qDebug("Ошибка. База данных не открыта");
    query = new QSqlQuery(db);
    model = new QSqlTableModel(this,db);
    model -> setTable("Склад");
    model ->select();
    ui ->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
}

sklad::~sklad()
{
    delete ui;
}
void sklad::on_sprav_clicked()
{
    window = new SPRPOLZOVAT(this);
    window -> show();
}
void sklad::on_udalen_clicked()
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

void sklad::on_dopol_clicked()
{
    window1 ->show();
}
void sklad::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

void sklad::on_vihod_clicked()
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

void sklad::on_obnov_clicked()
{
    QString id;
    QSqlQuery qry;
    qry.prepare("select * from Склад");
    model = new QSqlTableModel(this,db);
    model->setTable("Склад");
    model->select();
    ui->tableView->setModel(model);
}

void sklad::on_poisk_clicked()
{

char percent = '%';
QSqlQuery query;

QString querySearchString = QString("ID_сектора LIKE '%1%2' OR Название_товара LIKE '%1%2' OR Количество LIKE '%1%2'")
.arg(ui->poiskS->text()).arg(percent);



this->model->setFilter(querySearchString);
this->model->select();
this->ui->tableView->update();


}

void sklad::on_redak_clicked()
{
    window2->show();

}
