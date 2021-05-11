#ifndef DATALAYER_H
#define DATALAYER_H

#include <QString>
#include <QtSql>
#include <menu.h>
#include "employee_1.h"
#include "warning.h"
using namespace std;
class DataLayer
{
private:
    QSqlDatabase mydb;
    bool connectDB();
    void closeDB();

public:
    //DataLayer();
  bool addEmployee(QString);
  void addemp(QString n, QString c,int p,float s,QString t,QString pw,float h, float w);
void addfoo(QString n, double p, QString d, QString u, QString t);
    void removeemp(QString);
    void removefood(QString);
    void removedeal(QString);
    void getmenu();
    void InitMenu(Menu *  mm);
       bool retrieveEmployees(vector<Employee*>*);
             bool retrieveWarning(vector<Warning *>*);
            QSqlQuery retrvdeal();
            QSqlQuery retrvfooditemfordeal(QString nm);
    bool addDeal(QString n, double p, QString );
    void addDealFood(QString ,  QString, int );
};

#endif // DATALAYER_H
