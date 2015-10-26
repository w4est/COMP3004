#-------------------------------------------------
#
# Project created by QtCreator 2015-10-22T11:23:41
#
#-------------------------------------------------

QT       += core gui \
     sql

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = COMP3004
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    loggedin.cpp \
    register.cpp \
    editqualifications.cpp \
    ProfileEntity.cpp \
    StorageObject.cpp \
    SimpleFileStorage.cpp \
    StorageManager.cpp \
    MasterControl.cpp \
    LoginControl.cpp \

HEADERS  += login.h \
    loggedin.h \
    register.h \
    rapidxml.hpp \
    rapidxml_iterators.hpp \
    rapidxml_print.hpp \
    rapidxml_utils.hpp \
    editqualifications.h \
    ProfileEntity.h \
    StorageObject.h \
    SimpleFileStorage.h \
    StorageManager.h \
    MasterControl.h \
    LoginControl.h \

FORMS    += login.ui \
    loggedin.ui \
    register.ui \
    editqualifications.ui
