#ifndef BUSINESSLAYER_H
#define BUSINESSLAYER_H
#include <vector>
#include "employee_1.h"
#include <QString>
#include "warning.h"
//#include "reservation.h"

using namespace std;
class BusinessLayer
{
public:
   // BusinessLayer();
  bool addEmployee(QString);
  void adde(QString, QString ,int ,float,QString,QString, float ,float);
  void addf(QString n, double p, QString d, QString u, QString t);
   void rememp(QString);
   void remfood(QString);
  // bool retrieve(vector<Customer*>*);
     bool retrieveEmployee(vector<Employee*>*);
     bool retrieveWarning(vector <Warning *> *);
    bool remdeal(QString);
    bool adddeal(QString , double , QString );

    void addDfood(QString ,  QString, int );
};

#endif // BUSINESSLAYER_H
