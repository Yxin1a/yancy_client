#-------------------------------------------------
#
# Project created by QtCreator 2025-01-02T17:26:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = src_gui
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += $$PWD/../release/$$QT_ARCH/include

LIBS += -L$$PWD/../release/$$QT_ARCH/lib -lhv_static \
        -L$$PWD/../release/$$QT_ARCH/lib -lcjson

DESTDIR += $$PWD/../release/$$QT_ARCH/bin

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    IPC/ipc_client.cpp \
    IPC/ipc_protocol.cpp \
    Network/network_client.cpp

HEADERS += \
        mainwindow.h \
    IPC/ipc_client.h \
    IPC/ipc_protocol.h \
    ../tools/singleton.h \
    ../tools/list.h \
    ../tools/thread.h \
    Network/network_client.h

FORMS += \
        mainwindow.ui
