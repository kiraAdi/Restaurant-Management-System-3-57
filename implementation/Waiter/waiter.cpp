
#include "waiter.h"
#include <QtGui>
#include <iostream>
#include<qmessagebox.h>
#include<qsqlquery.h>
#include"qmenu.h"
#include <QComboBox>

waiter::waiter(QWidget *parent)
: QMainWindow(parent)
{

    ui.setupUi(this);
    QString servername = "dell-PC\\sqlexpress";
    QString dbname = "practice";
    mydb = QSqlDatabase::addDatabase("QODBC");
    mydb.setConnectOptions();
    QString dsn = QString("DRIVER={SQL Server};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername).arg(dbname);
    mydb.setDatabaseName(dsn);
    int i = 0;
    if (mydb.open())
    {

        QSqlQuery 	 query1("select * from Reservation_Table join Customer on Customer.CNIC=Reservation_Table.customer_id where Reservation_Table.waiter_cnic='1234567890123'");
        int p = query1.numRowsAffected();
        QString q = QString::number(p);
        ui.tableWidget->setRowCount(p);
        while (query1.next()) {

            QString country = query1.value(3).toString();
            QString country1 = query1.value(5).toString();
            QString country2 = query1.value(2).toString();

            ui.tableWidget->setItem(i, 0, new QTableWidgetItem(country));
            ui.tableWidget->setItem(i, 1, new QTableWidgetItem(country1));
            ui.tableWidget->setItem(i, 2, new QTableWidgetItem(country2));
          

            ++i;

        }


        //ui.tableWidget->setVerticalHeader(new myHeaderView());
        //	connect(ui.tableWidget, SIGNAL(sectionClicked(int)), this, SLOT(editSlot(int, int)));
        //

    }
}
void waiter::connetdb()
{

    if (ui.tableWidget->rowCount() != 0)
    {
        row = ui.tableWidget->currentIndex().row();

        QTableWidgetItem* itm = ui.tableWidget->item(row, 0);
        id= itm->text();
        int bill = 0;
        

        QSqlQuery query;
        query.prepare(" select amount from _Order  where customerid=:id ");
        query.bindValue(":id", id);
        query.exec();
        while (query.next())
        {


            int amnt = query.value(0).toInt();
			bill = bill + amnt;
            //ui.textEdit->setText(query.value(1).toString());

        }
		ui.textEdit->setText(QString::number(bill));
        //
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("no record found ");
        msgBox.exec();
    }
}
void waiter:: paybill()
{
    QString q = ui.textEdit->toPlainText();
    QString q1 = ui.textEdit_2->toPlainText();
    if (ui.tableWidget->rowCount() != 0)
    {
        if (q == q1)
        {
            if (q.isEmpty() || q1.isEmpty())
            {
                QMessageBox msgBox;
                msgBox.setText("no value entered");
                msgBox.exec();
            }
            else
            {

                ui.tableWidget->removeRow(row);
                ui.textEdit_2->setText("");
                ui.textEdit->setText("");
                QSqlQuery query;
                query.prepare(" delete from Reservation_Table where customer_id=:id ");
                query.bindValue(":id", id);
                query.exec();
                query.prepare("delete from _Order  where customerid=:id  ");
                query.bindValue(":id", id);
                query.exec();
                QMessageBox msgBox;
                msgBox.setText("bill has success fully recieved");
                msgBox.exec();
            }
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("sorry:given amount is not equal to bill");
            msgBox.exec();
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("no record found");
        msgBox.exec();
    }
    }



waiter::~waiter()
{

}
