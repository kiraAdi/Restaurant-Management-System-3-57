#-------------------------------------------------
#
# Project created by QtCreator 
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += widgets
CONFIG   += console
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = manager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    employee.cpp \
    fooditem.cpp \
    deal.cpp \
    businesslayer.cpp \
    datalayer.cpp \
    employee_1.cpp \
    fooditem_1.cpp \
    menu.cpp \
    deal_1.cpp \
    restaurant.cpp

HEADERS  += mainwindow.h \
    employee.h \
    fooditem.h \
    deal.h \
    businesslayer.h \
    datalayer.h \
    employee_1.h \
    fooditem_1.h \
    menu.h \
    deal_1.h \
    restaurant.h \
    warning.h

FORMS    += mainwindow.ui \
    employee.ui \
    fooditem.ui \
    deal.ui
