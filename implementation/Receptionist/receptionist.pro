QT += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = receptionist
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    menu.cpp \
    businesslayer.cpp \
    datalayer.cpp \
    employee.cpp \
    customer.cpp \
    sitting_arrangement.cpp \
    reservation.cpp \
    restaurant.cpp \
    fooditem.cpp \
    quantity.cpp \
    table.cpp \
    deal.cpp

HEADERS  += mainwindow.h \
    menu.h \
    businesslayer.h \
    datalayer.h \
    employee.h \
    customer.h \
    sitting_arrangement.h \
    reservation.h \
    restaurant.h \
    fooditem.h \
    quantity.h \
    table.h \
    deal.h

FORMS    += mainwindow.ui \
    menu.ui \
    quantity.ui
