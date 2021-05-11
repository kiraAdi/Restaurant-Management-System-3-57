/********************************************************************************
** Form generated from reading UI file 'waiter.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITER_H
#define UI_WAITER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_waiterClass
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *waiterClass)
    {
        if (waiterClass->objectName().isEmpty())
            waiterClass->setObjectName(QStringLiteral("waiterClass"));
        waiterClass->resize(618, 420);
        centralWidget = new QWidget(waiterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(5, 70, 601, 192));
        tableWidget->setColumnCount(3);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(180, 280, 161, 31));
        textEdit->setUndoRedoEnabled(false);
        textEdit->setReadOnly(true);
        textEdit->setAcceptRichText(false);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 280, 141, 31));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 320, 141, 31));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(180, 320, 161, 31));
        waiterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(waiterClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 618, 21));
        waiterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(waiterClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        waiterClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(waiterClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        waiterClass->setStatusBar(statusBar);

        retranslateUi(waiterClass);
        QObject::connect(pushButton, SIGNAL(clicked()), waiterClass, SLOT(connetdb()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), waiterClass, SLOT(paybill()));

        QMetaObject::connectSlotsByName(waiterClass);
    } // setupUi

    void retranslateUi(QMainWindow *waiterClass)
    {
        waiterClass->setWindowTitle(QApplication::translate("waiterClass", "waiter", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("waiterClass", "Customer ID", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("waiterClass", "Customer Name", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("waiterClass", "Table No", 0));
        pushButton->setText(QApplication::translate("waiterClass", "Genrate Customer  Bill", 0));
        pushButton_2->setText(QApplication::translate("waiterClass", "ReceieveBill", 0));
    } // retranslateUi

};

namespace Ui {
    class waiterClass: public Ui_waiterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITER_H
