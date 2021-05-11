#include "quantity.h"
#include "ui_quantity.h"
#include <QMessageBox>
#include <iostream>
using namespace std;
Quantity::Quantity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Quantity)
{
    ui->setupUi(this);
    ui->qty->setText("");
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
    setWindowTitle(tr("Quantity"));
    qty_closed=0;
    qt=0;

}

Quantity::~Quantity()
{
    delete ui;
}
void Quantity::setItemName(QString text,Menu*m,QCheckBox*check){
itemName=text;
ui->qty->setText("");
ui->label->setText(text);
men=m;
temp_cb=check;
}


void Quantity::on_pushButton_clicked()
{
    bool invalid_noc=0;
    for(int i=0;i<ui->qty->text().length();i++){
        if(ui->qty->text()[i]<QLatin1Char('0')||ui->qty->text()[i]>QLatin1Char('9')){
            QMessageBox msg;
            msg.setText("Quantity should be in numeric");
            msg.exec();
            invalid_noc=true;
            break;
        }
    }
    if(!invalid_noc){
        int q=ui->qty->text().toInt();
        if(q>0){
              this->qt=q;
             qty_closed=true;
             men->setBill(q,temp_cb);
            this->close();
        }
        else{
            QMessageBox msg;
            msg.setText("Quantity must be atleast 1");
            msg.exec();
        }
    }
}
