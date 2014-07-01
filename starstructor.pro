CONFIG += qt
CONFIG += console
CONFIG += c++11

console {
	DEFINES += ST_USE_CONSOLE
} else {
	DEFINES += ST_NO_USE_CONSOLE
}

QT += core gui widgets opengl

TARGET   = starstructor
TEMPLATE = app

RESOURCES += res/icon.qrc

QMAKE_CXXFLAGS += -std=c++11

## Source files

INCLUDEPATH += src/
INCLUDEPATH += src/gui/

HEADERS += src/stexception.hpp
HEADERS += src/ststlspecialisation.hpp
HEADERS += src/gui/stmainwindow.hpp
HEADERS += src/gui/steditorglwidget.hpp
HEADERS += src/utility/sttimer.hpp
HEADERS += src/utility/stlogger.hpp
HEADERS += src/utility/stdirectoryservices.hpp
HEADERS += src/core/stparseable.hpp
HEADERS += src/core/stjsonfile.hpp
HEADERS += src/core/stassetmanager.hpp
HEADERS += src/core/object/stasset.hpp
HEADERS += src/core/object/sttile.hpp
HEADERS += src/core/object/stnpc.hpp
HEADERS += src/core/object/stobject.hpp
HEADERS += src/core/object/stliquid.hpp
HEADERS += src/core/world/stlevel.hpp
HEADERS += src/core/world/stdungeonfile.hpp
HEADERS += src/core/world/stworldfile.hpp
HEADERS += src/core/world/ststructurefile.hpp

SOURCES += src/main.cpp
SOURCES += src/gui/stmainwindow.cpp
SOURCES += src/gui/steditorglwidget.cpp
SOURCES += src/utility/sttimer.cpp
SOURCES += src/utility/stlogger.cpp
SOURCES += src/utility/stdirectoryservices.cpp
SOURCES += src/core/stparseable.cpp
SOURCES += src/core/stjsonfile.cpp
SOURCES += src/core/stassetmanager.cpp
SOURCES += src/core/object/stasset.cpp
SOURCES += src/core/object/sttile.cpp
SOURCES += src/core/object/stnpc.cpp
SOURCES += src/core/object/stobject.cpp
SOURCES += src/core/object/stliquid.cpp
SOURCES += src/core/world/stlevel.cpp
SOURCES += src/core/world/stdungeonfile.cpp
SOURCES += src/core/world/stworldfile.cpp
SOURCES += src/core/world/ststructurefile.cpp

FORMS += src/gui/mainwindow.ui
