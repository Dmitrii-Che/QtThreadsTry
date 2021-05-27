QT       += core gui
QT += concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CHDV-2020-02-21
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++14

SOURCES += \
        main.cpp \
        threadmanager.cpp \
    mypoint.cpp \
    worker.cpp \
    myrunnable.cpp \
    mythread.cpp \
    mutexthread.cpp \
    semathread.cpp \
    systemsemathread.cpp

HEADERS += \
        threadmanager.h \
    mypoint.h \
    worker.h \
    myrunnable.h \
    mythread.h \
    mutexthread.h \
    semathread.h \
    systemsemathread.h

FORMS += \
        threadmanager.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
