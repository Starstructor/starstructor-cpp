QT += core gui
QT += widgets

TARGET   = starstructor
TEMPLATE = app

SOURCES	+= 	src/*.cpp \
			src/gui/*.cpp

HEADERS += 	src/*.hpp \
			src/gui/*.hpp

FORMS   +=  src/gui/*.ui
