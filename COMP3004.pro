#-------------------------------------------------
#
# Project created by QtCreator 2015-10-22T11:23:41
#
#-------------------------------------------------

QT       += core gui

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = COMP3004
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    loggedin.cpp \
    register.cpp \
    login_control.cpp \
    editqualifications.cpp \
    viewprofile.cpp \
    admincontrol.cpp \
    runppid.cpp \
    createproject.cpp \
    createproject2.cpp \
    project.cpp \
    qualification.cpp


HEADERS  += login.h \
    loggedin.h \
    register.h \
    login_control.h \
    /rapidxml-1.13/rapidxml.hpp \
    /rapidxml-1.13/rapidxml_iterators.hpp \
    /rapidxml-1.13/rapidxml_print.hpp \
    /rapidxml-1.13/rapidxml_utils.hpp \
    editqualifications.h \
    viewprofile.h \
    admincontrol.h \
    runppid.h \
    createproject.h \
    createproject2.h \
    project.h \
    qualification.h


FORMS    += login.ui \
    loggedin.ui \
    register.ui \
    editqualifications.ui \
    viewprofile.ui \
    admincontrol.ui \
    runppid.ui \
    createproject.ui \
    createproject2.ui
