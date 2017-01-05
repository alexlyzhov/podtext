CONFIG += qt debug
SOURCES += Main.cpp \
    mainwindow.cpp \
    downloader.cpp \
    source.cpp
TARGET = Main
QMAKE_CXXFLAGS += -lcurl -g -std=c++11
LIBS += -lcurl
QT += multimedia multimediawidgets

HEADERS += \
    mainwindow.h \
    downloader.h \
    source.h