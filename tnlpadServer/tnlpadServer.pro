#-------------------------------------------------
#
# Project created by QtCreator 2012-02-11T14:43:43
#
#-------------------------------------------------

QT       += core gui network

TARGET = tnlpadServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    user.cpp \
    nickcommand.cpp \
    messagecommand.cpp \
    logincommand.cpp \
    joincommand.cpp \
    drawcommand.cpp \
    command.cpp \
    clearcommand.cpp

HEADERS  += mainwindow.hpp \
    user.hpp \
    nickcommand.hpp \
    messagecommand.hpp \
    logincommand.hpp \
    joincommand.hpp \
    drawcommand.hpp \
    command.hpp \
    clearcommand.hpp

FORMS    += mainwindow.ui
