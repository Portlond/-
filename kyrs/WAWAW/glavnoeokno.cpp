#include "glavnoeokno.h"
#include "ui_glavnoeokno.h"
#include <QMessageBox>
#include <QDebug>
#include"../qq/qq.h"
#include<QTableView>
#include"sprpolzovat.h"
GLAVNOEOKNO::GLAVNOEOKNO(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GLAVNOEOKNO)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./TestDDB.db");
    if (db.open())
        qDebug("БАЗА ДАННЫХ ОТКРЫТА");
    else
        qDebug("ОШИБКА!БАЗА ДАННЫХ НЕ ОТКРЫТА!");
    query = new QSqlQuery(db);
    query -> exec("CREATE TABLE TestDDB(ИМЯ_РЕБЁНКА TEXT, ЕГО_РОСТ TEXT, ДАТА TEXT);");
    model = new QSqlTableModel(this,db);
    model -> setTable("TestDDB");
    model ->select();
    ui ->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);   //РАСТЯГИВАЕТ ПЕРВУЮ СЕКЦИЮ ТАБЛИЦЫ
}
GLAVNOEOKNO::~GLAVNOEOKNO()
{
    delete ui;
}
void GLAVNOEOKNO::on_sprG_clicked()
{
    window = new SPRPOLZOVAT(this);
    window -> show();
}
void GLAVNOEOKNO::on_udPOLZ_clicked()
{
    ui->statusbar->showMessage("Удаление позиции...");
    QMessageBox::warning(this,"УДАЛЕНИЕ ПОЗИЦИИ.","Позиция успешно удалена!");
    model->removeRow(row); //УДАЛЕНИЕ СТРОКИ ПО НО ЕЕ НОМЕРУ
    ui->statusbar->showMessage(" ");
}
void GLAVNOEOKNO::on_doPol_clicked()
{
    ui->statusbar->showMessage("Ребёнок добавлен...");
    QMessageBox::information(this,"ДОБАВЛЕНИЕ РЕБЁНКА.","Строка для заполнения информации о ребёнке была успешно добавлена!");
    model -> insertRow(model ->rowCount());
    ui->statusbar->showMessage(" ");
}
void GLAVNOEOKNO::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

void GLAVNOEOKNO::on_vihod_clicked()
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

void GLAVNOEOKNO::on_obnn_clicked()
{
    Qq p;
    p.obn();
}
