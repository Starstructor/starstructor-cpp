/*
Starstructor, the Starbound Toolet 
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#include "mainwindow.hpp"
#include "constants.hpp"

namespace Starstructor {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow{parent}
{
    m_appWindow.setupUi(this);

    setWindowTitle(windowTitle() + " v" 
        + QString::number(VERSION_MAJOR) + "." 
        + QString::number(VERSION_MINOR) + "." 
        + QString::number(VERSION_BUILD));
}

}