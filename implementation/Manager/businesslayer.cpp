#include "businesslayer.h"
#include "datalayer.h"
#include "employee_1.h"
bool BusinessLayer::addEmployee(QString cnic){
    DataLayer d;
   if(d.addEmployee(cnic)){
       return true;
   }
   else{
       return false;
   }
}
 void BusinessLayer::adde(QString n , QString c,int p ,float s,QString t,QString pw, float h ,float w)
 {
     DataLayer d;
     d.addemp(n, c,p, s, t, pw,h, w);
 }
 void BusinessLayer::addf(QString n, double p, QString d, QString u, QString t)
 {
     DataLayer dd;
     dd.addfoo(n,p,d, u,t);

 }
 void BusinessLayer::rememp(QString cnic) {
     DataLayer d;
     d.removeemp(cnic);
 }
 void BusinessLayer::remfood(QString name) {
     DataLayer d;
     d.removefood(name);
 }
 bool BusinessLayer::retrieveEmployee(vector<Employee*> *emp)
 {
     DataLayer d;
     if(d.retrieveEmployees(emp))
     {
         return true;
     }
     return false;
 }
bool BusinessLayer::retrieveWarning(vector <Warning *> * w) {
    DataLayer d;
    if(d.retrieveWarning(w))
    {
        return true;
    }
    return false;

}
bool BusinessLayer::remdeal(QString n) {
    DataLayer d;
    d.removedeal(n);
    return true;
}
bool BusinessLayer::adddeal(QString n, double p, QString d) {
    DataLayer dd;
    dd.addDeal(n, p, d);
    return true;
}
void BusinessLayer::addDfood(QString n ,  QString fn, int q) {
    DataLayer d;
    d.addDealFood(n ,fn, q);
}
