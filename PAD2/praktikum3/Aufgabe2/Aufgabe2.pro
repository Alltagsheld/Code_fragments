TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        gateway.cpp \
        knots.cpp \
        lightsensor.cpp \
        main.cpp \
        switch.cpp \
        thermometer.cpp

HEADERS += \
    gateway.h \
    knots.h \
    lightsensor.h \
    switch.h \
    thermometer.h
