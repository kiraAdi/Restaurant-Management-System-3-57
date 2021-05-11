#ifndef RATEDIALOG_H
#define RATEDIALOG_H

#include <QMainWindow>
#include <QDialog>
#include "order.h"
#include <qspinbox.h>
#include <QTableWidgetItem>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
	explicit Dialog(QWidget *parent = 0,Order *myOrder=new Order());
	vector<int> getRating();
    ~Dialog();
protected slots:
    void onSubmitRatingClicked();
	void setWaiterRating();
signals:
	void myDialogFinished(vector<int>);
private:
    Ui::Dialog *ui;
	vector<int> rating;
};

#endif // RATEDIALOG_H
