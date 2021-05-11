
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
#include "employee_1.h"
#include <QMessageBox>
#include "restaurant.h"
#include "Menu.h"
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m=new Manager_1();



    ui->setupUi(this);
    menu.Initialise();
    setlist();



    //QPushButton *ignorebutton=new QPushButton;
   // QListWidgetItem *item=new QListWidgetItem;
   // ui->foodrating->insertItem(1,item);
    //ui->foodrating->setItemWidget(item,ignorebutton);


}
void MainWindow::setlist() {
    int rcount=r.warn.size();


     ui->warnlist->setRowCount(rcount);

     for (int i=0; i<rcount;i++) {
        for(int j=0; j<r.employeelist.size(); j++) {
            cout<<r.warn[i]->getcnic().toStdString()<<endl;
            cout<<r.employeelist[j]->getCnic().toStdString()<<endl<<endl;
            if(r.warn[i]->getcnic().toInt() == r.employeelist[j]->getCnic().toInt()) {
                ui->warnlist->setItem(i, 0,  new QTableWidgetItem(r.employeelist[j]->getName()));
                ui->warnlist->setItem(i, 1, new QTableWidgetItem(QString::number(r.warn[i]->getcount())));
                ui->warnlist->setItem(i, 2, new QTableWidgetItem(r.employeelist[j]->getType()));
                ui->warnlist->setItem(i, 3, new QTableWidgetItem(r.warn[i]->getcnic()));
            break;

            }
        }
     }


 ui->warnlist->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addemp_clicked()
{

    /*if(m->AddEmployee("asdads")){
    QMessageBox msg;
    msg.setText("Connected");
    msg.exec();
    }
    else{
    QMessageBox msg;
    msg.setText("not connected");
    msg.exec();
    }
*/
e.show();
e.pattern1();

}

void MainWindow::on_additem_clicked()
{
    //this->hide();
    f.show();
    f.add();
}


void MainWindow::on_adddeal_clicked()
{
 //this->hide();
    d.show();
    d.foradd(menu);
}

void MainWindow::on_editemp_clicked()
{
    e.show();
    e.foredit(r);
}

void MainWindow::on_getsal_clicked()
{
       e.show();
       e.forsal(r);
}


void MainWindow::on_remitem_clicked()
{
    f.show();
    f.forremove(menu);
}

void MainWindow::on_edititem_clicked()
{
    f.show();
    f.edit(menu);
}

void MainWindow::on_remdeal_clicked()
{
    d.show();
    d.forremove();
    d.retrvdeallist();

}

void MainWindow::on_editdeal_clicked()
{
    d.show();
    d.foredit();
}
