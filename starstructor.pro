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

SOURCES += src/*.cpp
SOURCES += src/gui/*.cpp
            
HEADERS += src/*.hpp 
HEADERS += src/gui/*.hpp

FORMS   += src/gui/*.ui
