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

SOURCES += src/*.cpp
SOURCES += src/gui/*.cpp
            
HEADERS += src/*.hpp 
HEADERS += src/gui/*.hpp
HEADERS += src/exception/*.hpp

FORMS   += src/gui/*.ui