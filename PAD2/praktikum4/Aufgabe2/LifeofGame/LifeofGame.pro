TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        cell.cpp \
        field.cpp \
        gameoflife.cpp \
        main.cpp

HEADERS += \
    cell.h \
    field.h \
    gameoflife.h
