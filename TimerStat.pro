#-------------------------------------------------
#
# Project created by Aaron Lopez 2016-05-08T19:32:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TimerStat
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fileeditdialog.cpp

HEADERS  += mainwindow.h \
    fileeditdialog.h

FORMS    += mainwindow.ui \
    fileeditdialog.ui

RESOURCES += \
    resouces.qrc
