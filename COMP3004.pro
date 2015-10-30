#-------------------------------------------------
#
# Project created by QtCreator 2015-10-22T11:23:41
#
#-------------------------------------------------

QT       += core gui \
     sql

QMAKE_CXXFLAGS += -std=c++11

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
    AdminControl.cpp \
    StudentControl.cpp \
    LoginControl.cpp \
    qualframe.cpp \
    login_control.cpp \
    admincontrol.cpp \
    runppid.cpp \
    createproject.cpp \
    createproject2.cpp \
    project.cpp \
    qualification.cpp \
    editproject.cpp \
    adminview.cpp \
    profileview.cpp \
    sqlstorage.cpp \
    projectframe.cpp

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
    AdminControl.h \
    StudentControl.h \
    LoginControl.h \
    qualframe.h \
    login_control.h \
    admincontrol.h \
    runppid.h \
    createproject.h \
    createproject2.h \
    project.h \
    qualification.h \
    editproject.h \
    adminview.h \
    profileview.h \
    sqlstorage.h \
    projectframe.h


FORMS    += login.ui \
    loggedin.ui \
    register.ui \
    editqualifications.ui \
    qualframe.ui \
    admincontrol.ui \
    runppid.ui \
    createproject.ui \
    createproject2.ui \
    editproject.ui \
    adminview.ui \
    profileview.ui \
    masterwindow.ui \
    projectframe.ui
