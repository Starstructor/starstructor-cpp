/*
Starstructor, the Starbound Toolet 
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#include "mainwindow.hpp"

namespace Starstructor { namespace GUI {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow{parent}
{
    m_appWindow.setupUi(this);
}

}

}