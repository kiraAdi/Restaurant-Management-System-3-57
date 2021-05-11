#ifndef SITTINGARRANGEMENT
#define SITTINGARRANGEMENT
#include<vector>
#include<string>
#include <QMainWindow>
#include "table.h"
using namespace std;
namespace Ui {
class SittingArrangement;
}

class SittingArrangement : public QMainWindow
{
    Q_OBJECT

public:
virtual void foo()=0;//added to make class pure virtual
    explicit SittingArrangement(QWidget *parent = 0);
    ~SittingArrangement();

private:
    Ui::SittingArrangement *ui;
    vector<Table*> table;
};
class OpenAir:public SittingArrangement
{




};
//hall is abstract
class Hall:public SittingArrangement
{



};
class Formal:public Hall
{



};
//informal is abstract
class Informal:public Hall
{


};

class Meeting:public Informal
{



};
class Ceremony:public Informal
{


};

#endif // SITTINGARRANGEMENT

