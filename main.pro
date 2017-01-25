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
    src/parser.cpp \
    src/textview.cpp \
    src/playerthread.cpp
TARGET = Main
LIBS = -lopenal -lmpg123 -lao
QMAKE_CXXFLAGS += -g -std=c++11 -lopenal
QT += multimedia multimediawidgets network widgets

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
    src/parser.h \
    src/textview.h \
    src/playerthread.h

DISTFILES += \
    repo.json \
    settings.json

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../lib/release/ -lmpg123
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../lib/debug/ -lmpg123
#else:unix: LIBS += -L$$PWD/../../../../../lib/ -lmpg123

#INCLUDEPATH += $$PWD/../../../../../usr/include
#DEPENDPATH += $$PWD/../../../../../usr/include
