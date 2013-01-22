#-------------------------------------------------
#
# Project created by QtCreator 2012-02-10T19:27:10
#
#-------------------------------------------------

QT       += core gui network

TARGET = tnlpad
TEMPLATE = app


SOURCES += main.cpp\
        joinwindow.cpp \
    networkengine.cpp \
    command.cpp \
    canvaswindow.cpp \
    canvaswidget.cpp \
    drawcommand.cpp \
    joincommand.cpp \
    nickcommand.cpp \
    messagecommand.cpp \
    logincommand.cpp \
    clearcommand.cpp \
    user.cpp

HEADERS  += joinwindow.hpp \
    networkengine.hpp \
    command.hpp \
    canvaswindow.hpp \
    canvaswidget.hpp \
    drawcommand.hpp \
    joincommand.hpp \
    nickcommand.hpp \
    messagecommand.hpp \
    logincommand.hpp \
    clearcommand.hpp \
    user.hpp

FORMS    += joinwindow.ui \
    canvaswindow.ui
