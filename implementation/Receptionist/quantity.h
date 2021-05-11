
#ifndef QUANTITY_H
#define QUANTITY_H
#include "menu.h"
#include <QDialog>
#include <QCheckBox>
class Menu;
namespace Ui {
class Quantity;
}

class Quantity : public QDialog
{
    Q_OBJECT

public:
    explicit Quantity(QWidget *parent = 0);
    ~Quantity();
    void setItemName(QString text,Menu*,QCheckBox*);
    QString getItemName();
    int qt;
    bool qty_closed;
private slots:
    void on_pushButton_clicked();

private:
    Ui::Quantity *ui;
    QString itemName;
    Menu*men;
    QCheckBox *temp_cb;

};

#endif // QUANTITY_H
