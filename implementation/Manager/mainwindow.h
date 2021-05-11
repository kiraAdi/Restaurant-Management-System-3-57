#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fooditem.h"
#include "employee_1.h"
#include "employee.h"
#include "deal.h"
#include "menu.h"
#include "restaurant.h"
#include <vector>
#include <iostream>
using namespace std;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    friend class fooditem;
public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addemp_clicked();
void setlist();

    void on_additem_clicked();

    void on_adddeal_clicked();

    void on_editemp_clicked();

    void on_getsal_clicked();

    void on_remitem_clicked();

    void on_edititem_clicked();

    void on_remdeal_clicked();

    void on_editdeal_clicked();
signals:
    void sendRestaurant(Restaurant*_r);
private:
    Ui::MainWindow *ui;

    Manager_1 *m;
    Menu menu;
    Restaurant r;


    employee e;
fooditem f;
    Deal d;
};


#endif // MAINWINDOW_H
