TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    src/coordinate.c \
    src/rectangle.c

HEADERS += \
    inc/coordinate.h \
    inc/rectangle.h
