#include "datalayer.h"
#include <QString>
#include <QtSql>
#include <iostream>
#include <QtWidgets/QMainWindow>
#include <QtCore/QCoreApplication>
#include<QWidget>
#include<ostream>
#include<iostream>
#include<QFile>
#include<QTime>
#include <stdio.h>
#include <QTextStream>
#include<QSqlDatabase>
#include<QSqlDriver>
#include <QDebug>
#include <QSqlQuery>
#include "employee_1.h"
#include "warning.h"
bool DataLayer::connectDB(){
    QString servername="dell-pc\\sqlexpress";
        QString dbname="practice";
         mydb = QSqlDatabase::addDatabase("QODBC");
        mydb.setConnectOptions();
        QString dsn=QString("DRIVER={SQL Server};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername).arg(dbname);
        mydb.setDatabaseName(dsn);
        if(mydb.open()){
            return true;
            std::cout<<"oppended"<<endl;
        }

        else{

            std::cout<<"close"<<endl;
            return false;
        }

return true;
}
void DataLayer::closeDB(){
    mydb.close();
    //mydb.removeDatabase(QSqlDatabase::defaultConnection);
}


bool DataLayer::addEmployee(QString cnic){
    if(connectDB()){

       closeDB();
       return true;
    }
    else{
        return false;
    }
}
void DataLayer::addemp(QString n, QString c,int p,float s,QString t,QString pw,float h, float w)
{
    if(connectDB()){
        removeemp(c);
        cout<<"hello"<<endl;
QSqlQuery query;
double d=static_cast<double>(s);
double dd=static_cast<double>(h);
double ddd=static_cast<double>(w);
cout<<"In query func"<<endl;
query.prepare("insert into Employee(Name,CNIC,Phone_no,_Type,Salary) values(:name,:cnic,:phone,:type,:salary)");
query.bindValue(":name",n);
query.bindValue(":cnic",c);
query.bindValue(":phone",p);
query.bindValue(":salary",d);
query.bindValue(":type",t);
query.bindValue(":password",pw);
query.exec();
       closeDB();
       //return true;
    }
}
void DataLayer::addfoo(QString n, double p, QString d, QString u, QString t)
{
    if(connectDB()) {
 qDebug()<<"connected";
 removefood(n);
        QSqlQuery query;

query.prepare("insert into [Food Item] (name, Price, details, units, type) values ('"+n+"',:pp, '"+d+"', '"+u+"','"+t+"')");

query.bindValue(":pp",p);

query.exec();
query.prepare("insert into Menu(Name,_Description,Price,_type) values('"+n+"','"+d+"',:price,'"+t+"') ");
query.bindValue(":price",p);
query.exec();
    }
    else {
        qDebug()<<"not connected";

    }
}
void DataLayer::removeemp(QString cnic) {
    if (connectDB()) {
        qDebug()<<"connected";
        QSqlQuery q;
        q.prepare ("Delete from employee where cnic='"+cnic+"' ");
        q.exec();
        q.prepare ("Delete from warning where cnic='"+cnic+"' ");
        q.exec();
    }
    else {qDebug()<<"not connected";
}
}

void DataLayer::removefood(QString name) {
    if (connectDB()) {
        qDebug()<<"connected";
        QSqlQuery q;
        q.prepare ("Delete from [Food Item] where name='"+name+"' ");
        q.exec();
        q.prepare("Delete from Menu where Name='"+name+"'");
        q.exec();
        q.prepare ("Delete from [dealitems] where fooditems='"+name+"' ");
        q.exec();
    }
    else {qDebug()<<"not connected";
}
}

void DataLayer::removedeal(QString name) {
    if (connectDB()) {
        qDebug()<<"connected";
        QSqlQuery q;
        q.prepare ("Delete from [deals] where name='"+name+"' ");
        q.exec();
        QSqlQuery qq;
        qq.prepare ("Delete from [dealitems] where name='"+name+"' ");

        qq.exec();
    }
    else {qDebug()<<"not connected";
}
}




void DataLayer::InitMenu(Menu  * mm) {
if (connectDB()) {
    qDebug()<<"connected";
    QSqlQuery q;
    q.prepare ("select * from [food item] ");
    q.exec();
  //  int count = q.numRowsAffected();

    while(q.next()){
        QString name = q.value(0).toString();
        float price = q.value(1).toFloat();
        QString details = q.value(2).toString();
        QString unit = q.value(3).toString();
        QString type = q.value(4).toString();
        mm->Add(name, price, details, unit, type);
    }
            closeDB();
            //return true;


}
else {qDebug()<<"not connected";
}

}


bool DataLayer::retrieveWarning(vector<Warning *> *warn)
{
    if(connectDB())
    {
        QSqlQuery qry;
        Warning * w;
        qry.prepare("select * from warning");
        if(qry.exec())
        {
            while(qry.next())
            {
                //cout<<qry.value("CNIC").toString().toStdString()<<endl;

                    w=new Warning;

                    QString cnic=qry.value("cnic").toString();

                    int count=qry.value("cnt").toInt();

                    //cout<<name.toStdString()<<endl;
                        w->set(cnic,count);
                        warn->push_back(w);
                    }
                }

            return true;
        }

    return false;
}


bool DataLayer::retrieveEmployees(vector<Employee*> *emp)
{
    if(connectDB())
    {
        QSqlQuery qry;
        Employee *e;
        qry.prepare("select * from employee");
        if(qry.exec())
        {
            while(qry.next())
            {
                //cout<<qry.value("CNIC").toString().toStdString()<<endl;

                    e=new Employee;

                    QString cnic=qry.value("cnic").toString();
                    QString name=qry.value("name").toString();
                    QString type=qry.value("_Type").toString();
                    int phone_no=qry.value("phone").toInt();
                    float salary=qry.value("salary").toFloat();
                    QString password=qry.value("password").toString();
                    float rate=qry.value("hourlyrate").toInt();
                    float work=qry.value("hoursworked").toFloat();

                    //cout<<name.toStdString()<<endl;
                        e->setAttributes(name,cnic,type,phone_no,salary, password,rate,work);
                        emp->push_back(e);
                    }
                }

            return true;
        }

    return false;
}
QSqlQuery DataLayer::retrvdeal()
{
    if(connectDB())
    {
    QSqlQuery query("select*from deals");

    return query;
    }
}
QSqlQuery DataLayer::retrvfooditemfordeal(QString nm)
{
    if(connectDB())
    {
        QSqlQuery query;

        query.prepare("select* from [dealItems] where name='"+nm+"' ");
        //query.bindValue(":nm",nm);
      query.exec();

    return query;
    }
}

bool DataLayer::addDeal(QString n, double p, QString d) {
    if(connectDB()) {
 qDebug()<<"connected";
 removedeal(n);
        QSqlQuery query;

query.prepare("insert into deals (name, Price,details) values ('"+n+"',:pp,'"+d+"')");

query.bindValue(":pp",p);

query.exec();
return true;
    }
    else {
        qDebug()<<"not connected";
return false;
    }
}
void DataLayer::addDealFood(QString n,  QString fn, int q ) {
    if(connectDB()) {
 qDebug()<<"connected";

 QSqlQuery query;

query.prepare("insert into dealitems (name, fooditem, quantity) values ('"+n+"','"+fn+"',:pp )");
query.bindValue(":pp",q);

query.exec();

    }
    else {
        qDebug()<<"not connected";
}


}
