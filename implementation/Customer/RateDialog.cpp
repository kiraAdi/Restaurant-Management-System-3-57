#include "RateDialog.h"
#include "ui_RateDialog.h"

Dialog::Dialog(QWidget *parent,Order* myOrder) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    rating.emplace_back(0);

	for(int i=0;i<myOrder->getItemList().size();++i)
	{
		ui->orderedItems->insertRow(i);
		QTableWidgetItem *w=new QTableWidgetItem();
		w->setText(QString::fromStdString(myOrder->getItemList()[i].getFoodItem()->getName()));
		ui->orderedItems->setItem(i,0,w);
		QSpinBox* rateBox=new QSpinBox();
		rateBox->setMinimum(-1);
		rateBox->setMaximum(1);
		ui->orderedItems->setCellWidget(i,1,rateBox);
	}
	for(int i=0;i<myOrder->getDealsOrdered().size();++i)
	{
		ui->orderedItems->insertRow(i);
		QTableWidgetItem *w=new QTableWidgetItem();
		w->setText(QString::fromStdString(myOrder->getDealsOrdered()[i].getName()));
		ui->orderedItems->setItem(i,0,w);
		QSpinBox* rateBox=new QSpinBox();
		rateBox->setMinimum(-1);
		rateBox->setMaximum(1);
		ui->orderedItems->setCellWidget(i,1,rateBox);
    }
}

void Dialog::setWaiterRating()
{
	if(ui->radioButton->isChecked())
		rating[0]=-1;
	else if(ui->waiterRate_2->isChecked())
		rating[0]=0;
	else if (ui->waiterRate->isChecked())
		rating[0]=1;
}

vector<int> Dialog::getRating()
{
	return rating;
}

void Dialog::onSubmitRatingClicked()
{
	for(int i=0;i<ui->orderedItems->rowCount();++i)
	{
		QSpinBox* takeQuantity=(QSpinBox*)ui->orderedItems->cellWidget(i,1);
		int p=takeQuantity->value();
		rating.emplace_back(p);
	}
	delete this;
}

Dialog::~Dialog()
{
    delete ui;
}
