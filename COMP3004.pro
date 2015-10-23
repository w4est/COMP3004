#-------------------------------------------------
#
# Project created by QtCreator 2015-10-22T11:23:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = COMP3004
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    loggedin.cpp \
    register.cpp \
    login_control.cpp

HEADERS  += login.h \
    loggedin.h \
    register.h \
    login_control.h \
    /rapidxml-1.13/rapidxml.hpp \
    /rapidxml-1.13/rapidxml_iterators.hpp \
    /rapidxml-1.13/rapidxml_print.hpp \
    /rapidxml-1.13/rapidxml_utils.hpp

FORMS    += login.ui \
    loggedin.ui \
    register.ui
