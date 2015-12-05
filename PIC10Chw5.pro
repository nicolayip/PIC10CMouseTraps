#-------------------------------------------------
#
# Project created by QtCreator 2015-10-29T23:33:19
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PIC10Chw5
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gameboard.cpp \
    traps.cpp

HEADERS  += mainwindow.h \
    gameboard.h \
    traps.h

FORMS    += mainwindow.ui \
    gameboard.ui

RESOURCES += \
    images.qrc
