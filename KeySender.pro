#-------------------------------------------------
#
# Project created by QtCreator 2016-01-11T14:35:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KeySender
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    xwrapper.cpp

HEADERS  += mainwindow.h \
    xwrapper.h

FORMS    += mainwindow.ui

LIBS += -lX11
