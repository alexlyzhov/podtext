CONFIG += qt debug
SOURCES += \
    mainwindow.cpp \
    downloader.cpp \
    source.cpp \
    main.cpp \
    listwidget.cpp \
    playerwidget.cpp \
    data.cpp
TARGET = Main
QMAKE_CXXFLAGS += -lcurl -g -std=c++11
LIBS += -lcurl
QT += multimedia multimediawidgets network

HEADERS += \
    mainwindow.h \
    downloader.h \
    source.h \
    listwidget.h \
    playerwidget.h \
    data.h
