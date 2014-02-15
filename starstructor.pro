CONFIG += qt
CONFIG += console

console {
	DEFINES += ST_USE_CONSOLE
} else {
	DEFINES += ST_NO_USE_CONSOLE
}

QT += core gui
QT += widgets
QT += opengl

TARGET   = starstructor
TEMPLATE = app

RESOURCES += res/icon.qrc

QMAKE_CXXFLAGS += -std=c++11

## Source files

INCLUDEPATH += src/

HEADERS += src/stexception.hpp
HEADERS += src/ststlspecialisation.hpp
HEADERS += src/gui/stmainwindow.hpp
HEADERS += src/utility/sttimer.hpp
HEADERS += src/utility/stlogger.hpp
HEADERS += src/utility/stdirectoryservices.hpp
HEADERS += src/core/stparseable.hpp
HEADERS += src/core/stjsonfile.hpp
HEADERS += src/core/stassetmanager.hpp
HEADERS += src/core/object/stasset.hpp
HEADERS += src/core/object/stmaterial.hpp
HEADERS += src/core/object/stnpc.hpp
HEADERS += src/core/object/stobject.hpp
HEADERS += src/core/object/stliquid.hpp
HEADERS += src/core/world/stlevel.hpp
HEADERS += src/core/world/stdungeonfile.hpp
HEADERS += src/core/world/stworldfile.hpp
HEADERS += src/core/world/ststructurefile.hpp

SOURCES += src/main.cpp
SOURCES += src/gui/stmainwindow.cpp
SOURCES += src/utility/sttimer.cpp
SOURCES += src/utility/stlogger.cpp
SOURCES += src/utility/stdirectoryservices.cpp
SOURCES += src/core/stparseable.cpp
SOURCES += src/core/stjsonfile.cpp
SOURCES += src/core/stassetmanager.cpp
SOURCES += src/core/object/stasset.cpp
SOURCES += src/core/object/stmaterial.cpp
SOURCES += src/core/object/stnpc.cpp
SOURCES += src/core/object/stobject.cpp
SOURCES += src/core/object/stliquid.cpp
SOURCES += src/core/world/stlevel.cpp
SOURCES += src/core/world/stdungeonfile.cpp
SOURCES += src/core/world/stworldfile.cpp
SOURCES += src/core/world/ststructurefile.cpp

FORMS += src/gui/mainwindow.ui
