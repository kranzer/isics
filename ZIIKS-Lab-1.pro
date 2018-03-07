#-------------------------------------------------
#
# Project created by QtCreator 2018-02-20T20:24:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZIIKS-Lab-1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    loginwindow.cpp \
    storage.cpp \
    mainscreen_admin.cpp \
    mainscreen_user.cpp \
    changepasswordmodal.cpp \
    changeusermodemodal.cpp \
    addusermodal.cpp \
    addrestrictionsmodal.cpp \
    listusersmodal.cpp \
    about.cpp

HEADERS += \
    loginwindow.h \
    storage.h \
    mainscreen_admin.h \
    mainscreen_user.h \
    changepasswordmodal.h \
    changeusermodemodal.h \
    addusermodal.h \
    addrestrictionsmodal.h \
    listusersmodal.h \
    about.h

FORMS += \
    login.ui \
    changepasswordmodal.ui \
    mainscreen_user.ui \
    mainscreen_admin.ui \
    changeusermodemodal.ui \
    addusermodal.ui \
    addrestrictionsmodal.ui \
    listusersmodal.ui \
    about.ui
