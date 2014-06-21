#include "work.h"
#include <QString>
#include <QStandardItemModel>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDialog>
#include <QWidget>
#include <QHBoxLayout>


Form::Form(QWidget *parent) :
    QWidget(parent),
    workwindow(new Ui::Form)
{
    workwindow->setupUi(this);
    line_number = 0;
    model = new QStandardItemModel;
    model->setColumnCount(4);
    model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("Name"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("Sex"));
    model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("Birth"));
    model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("Birthaddr"));
    workwindow->tableView->setModel(model);
    workwindow->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

}

Form::~Form()
{
    delete workwindow;
}

void Form::on_pushButton_clicked()
{

}

void Form::on_lineEdit_5_editingFinished()
{
    char find_ojbect_flag=0;
    QString barcode = workwindow->lineEdit_5->text();
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    QSqlQuery query(db);
    db.setHostName("localhost");
    db.setDatabaseName("pos_data");
    db.setUserName("root");
    db.setPassword("");
    if(db.open()){
       query.exec("select *from price");
       while(query.next())
       {
           if(barcode == query.value(0).toString())
           {
               find_ojbect_flag = 1;
               model->setItem(line_number,0,new QStandardItem(query.value(0).toString()));
               model->setItem(line_number,1,new QStandardItem(query.value(1).toString()));
               model->setItem(line_number,2,new QStandardItem(query.value(2).toString()));
               model->setItem(line_number++,3,new QStandardItem(query.value(3).toString()));
           }
       }
       db.close();
       workwindow->lineEdit_5->clear();
       if(!find_ojbect_flag&&(barcode!=0))
       {
           QMessageBox::information(0,"Error:","Can not Find \""+barcode+"\" information",QMessageBox::Ok,QMessageBox::Ok);
       }
   }
    else
    {
        QMessageBox::information(0,"Warmming:","Can not connect to MYSQL!",QMessageBox::Ok,QMessageBox::Ok);
    }
}

void Form::on_pushButton_3_clicked()
{
    int i = 0;
    if(line_number>i)
    {
        line_number--;
        model->removeRow(i);
    }
}

void Form::on_pushButton_10_clicked()
{
    model->removeRows(0,line_number);
    line_number = 0;
}
