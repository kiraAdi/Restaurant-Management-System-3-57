#ifndef WAITER_H
#define WAITER_H
#include <QtGui>
#include <QtWidgets/QMainWindow>
#include "ui_waiter.h"
#include <QtCore/QCoreApplication>
#include<QWidget>
#include<ostream>
#include<iostream>
#include<QFile>
#include<QTime>
#include <stdio.h>
#include <QTextStream>
#include<QSqlDatabase>
#include<QSqlDriver>
#include <QSqlQuery>
#include <iostream>


class waiter : public QMainWindow
{
	Q_OBJECT

public:
	waiter(QWidget *parent = 0);
	
	~waiter();

	public slots:
	void paybill();
	void connetdb();
public:
	int row;
	QString id;
	Ui::waiterClass ui;
	QSqlDatabase		mydb;
};

#endif // WAITER_H
