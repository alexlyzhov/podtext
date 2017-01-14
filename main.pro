CONFIG += qt debug
SOURCES += \
#    mainwindow.cpp \
#    downloader.cpp \
#    source.cpp \
#    main.cpp \
#    listwidget.cpp \
#    playerwidget.cpp \
#    data.cpp \
#    repo.cpp \
#    settings.cpp \
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
#    mainwindow.h \
#    downloader.h \
#    source.h \
#    listwidget.h \
#    playerwidget.h \
#    data.h \
#    repo.h \
#    settings.h \
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
