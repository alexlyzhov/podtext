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
    src/source.cpp \
    src/remotesource.cpp \
    src/localsource.cpp \
    src/remotedata.cpp \
    src/localdata.cpp \
    src/datacreator.cpp \
    src/reader.cpp \
    src/parser.cpp
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
    src/source.h \
    src/remotesource.h \
    src/localsource.h \
    src/remotedata.h \
    src/localdata.h \
    src/datacreator.h \
    src/reader.h \
    src/parser.h

DISTFILES += \
    repo.json \
    settings.json
