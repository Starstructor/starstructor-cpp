CONFIG += qt
CONFIG += console

QT += core gui
QT += widgets
QT += opengl

win32
{
    RC_FILE = res/icon.rc
}

TARGET   = starstructor
TEMPLATE = app

INCLUDEPATH += src/ 
INCLUDEPATH += src/gui/
INCLUDEPATH += src/exception/
#INCLUDEPATH += src/test/
#INCLUDEPATH += src/utility/
INCLUDEPATH += src/core/
INCLUDEPATH += src/core/object/
INCLUDEPATH += src/core/world/

SOURCES += src/*.cpp
SOURCES += src/gui/*.cpp
#SOURCES += src/exception/*.cpp
#SOURCES += src/test/*.cpp
#SOURCES += src/utility/*.cpp
SOURCES += src/core/*.cpp
SOURCES += src/core/object/*.cpp
SOURCES += src/core/world/*.cpp
            
HEADERS += src/*.hpp 
HEADERS += src/gui/*.hpp
HEADERS += src/exception/*.hpp
#HEADERS += src/test/*.hpp
#HEADERS += src/utility/*.hpp
HEADERS += src/core/*.hpp
HEADERS += src/core/object/*.hpp
HEADERS += src/core/world/*.hpp

FORMS   += src/gui/*.ui