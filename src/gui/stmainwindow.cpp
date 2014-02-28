/*
Starstructor, the Starbound Toolet 
Copyright (C) 2013-2014 Chris Stamford
Licensed under terms of The MIT License (MIT)

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com
*/

#include "gui/stmainwindow.hpp"

namespace Starstructor { namespace GUI {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow{parent}
{
    m_mainWindow.setupUi(this);
}

}

}