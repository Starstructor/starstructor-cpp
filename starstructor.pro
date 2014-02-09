CONFIG += qt
CONFIG += console

QT += core gui
QT += widgets
QT += opengl

TARGET   = starstructor
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

RESOURCES += res/icon.qrc



## Source files

INCLUDEPATH += src/

HEADERS += src/core/stjsonfile.hpp
HEADERS += src/core/object/stasset.hpp
HEADERS += src/core/object/stmaterial.hpp
HEADERS += src/core/object/stnpc.hpp
HEADERS += src/core/object/stobject.hpp
HEADERS += src/core/world/stdungeonfile.hpp
HEADERS += src/core/world/stshipfile.hpp
HEADERS += src/core/world/stworldfile.hpp
HEADERS += src/exception/stexception.hpp
HEADERS += src/gui/stmainwindow.hpp

SOURCES += src/core/stjsonfile.cpp
SOURCES += src/core/object/stasset.cpp
SOURCES += src/core/object/stmaterial.cpp
SOURCES += src/core/object/stnpc.cpp
SOURCES += src/core/object/stobject.cpp
SOURCES += src/core/world/stdungeonfile.cpp
SOURCES += src/core/world/stshipfile.cpp
SOURCES += src/core/world/stworldfile.cpp
SOURCES += src/gui/stmainwindow.cpp
SOURCES += src/main.cpp

FORMS += src/gui/mainwindow.ui
