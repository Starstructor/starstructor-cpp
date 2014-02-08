/*
Starstructor, the Starbound Toolet 
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#include "stmainwindow.hpp"

namespace Starstructor { namespace GUI {

STMainWindow::STMainWindow(QWidget* parent) :
    QMainWindow{parent}
{
    m_mainWindow.setupUi(this);
}

}

}