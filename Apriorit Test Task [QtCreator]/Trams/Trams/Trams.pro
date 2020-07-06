TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    file.cpp \
    filereader.cpp \
    filewriter.cpp

HEADERS += \
    file.h \
    filereader.h \
    filewriter.h
