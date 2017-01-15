CONFIG += qt debug
SOURCES += \
    src/data.cpp \
    src/downloader.cpp \
    src/listwidget.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/playerwidget.cpp \
    src/repo.cpp \
    src/settings.cpp \
    src/source.cpp
TARGET = Main
QMAKE_CXXFLAGS += -g -std=c++11
QT += multimedia multimediawidgets network

HEADERS += \
    src/data.h \
    src/downloader.h \
    src/listwidget.h \
    src/mainwindow.h \
    src/playerwidget.h \
    src/repo.h \
    src/settings.h \
    src/source.h

DISTFILES += \
    repo.json
