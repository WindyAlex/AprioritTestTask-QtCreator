include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

INCLUDEPATH += ../Trams

HEADERS += \
        ../Trams/file.h \
        ../Trams/filereader.h \
        ../Trams/filewriter.h \
        filereaderTests.h \
        filewriterTests.h

SOURCES += \
        ../Trams/file.cpp \
        ../Trams/filereader.cpp \
        ../Trams/filewriter.cpp \
        main.cpp
