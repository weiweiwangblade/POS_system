#include "widget.h"
#include "work.h"
#include <QString>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QStringList>
#include <QHeaderView>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    loginwindow(new Ui::Widget)
{
    window = new QWidget;
    lineEdit = new QLineEdit;
    lineEdit_2 = new QLineEdit;
    qDebug()<<lineEdit->text();
    loginwindow->setupUi(this);

}

Widget::~Widget()
{
    delete loginwindow;
}

void Widget::on_pushButton_clicked()
{
    char name_find = 0;
    QDateTime time = QDateTime::currentDateTime();//Get Operation System time
    QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    QSqlQuery query(db);
    QString username = loginwindow->lineEdit->text();
    QString userpassword = loginwindow->lineEdit_2->text();
    QString name;
    QString password;
    db.setHostName("localhost");
    db.setDatabaseName("pos_data");
    db.setUserName("root");
    db.setPassword("");
    if(!db.open()){
        QMessageBox::information(0,"Error","Can not connect to service.",QMessageBox::Ok);
    }else{
        query.exec("select *from price");//check command
        while(query.next())
        {

            name = query.value(0).toString();
            password = query.value(3).toString();
            qDebug()<<name<<password;
            qDebug()<<username<<userpassword;
            if((username == name)&&(userpassword == password))
            {
                name_find = 1;
                this->close();
               switch(QMessageBox::information(0,"Data","Now time is: "+str,QMessageBox::Ok,QMessageBox::Ok))
               {
               case QMessageBox::Ok:
                   show_work_window();
                   break;
               default:
                   break;
               }
               break;
            }
        }
        db.close();
        if(!name_find)
        {
            QMessageBox::information(0,"Error","Wrong username or password",QMessageBox::Ok);
           loginwindow->lineEdit->clear();
            loginwindow->lineEdit_2->clear();
        }
    }
}
void Widget::show_work_window()
{
    workwindow.show();
}

void Widget::on_pushButton_2_clicked()
{
    close();
}

