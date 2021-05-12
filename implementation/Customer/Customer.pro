#-------------------------------------------------
#
# Project created by QtCreator 
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Customer
TEMPLATE = app


SOURCES += main.cpp\
    RateDialog.cpp \
    restaurant.cpp \
    menu.cpp \
    order.cpp \
    employee.cpp \
    fooditem.cpp \
    customer.cpp \
    deal.cpp \
    itemwithamount.cpp \
    sitting_arrangement.cpp \
    table.cpp \
    reservation.cpp

HEADERS  += \
    RateDialog.h \
    reservation.h \
    restaurant.h \
    menu.h \
    order.h \
    employee.h \
    fooditem.h \
    customer.h \
    deal.h \
    itemwithamount.h \
    sitting_arrangement.h \
    table.h \
    reservation.h

FORMS    +=    RateDialog.ui \
    restaurant.ui
