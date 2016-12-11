#-------------------------------------------------
#
# Project created by QtCreator 2016-12-10T20:19:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = colorvu
TEMPLATE = app


SOURCES += main.cpp\
        mainview.cpp \
    startup.cpp \
    utils.cpp

HEADERS  += mainview.hpp \
    startup.hpp \
    utils.hpp

FORMS    += mainview.ui
