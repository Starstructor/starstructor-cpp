/*
Starstructor, the Starbound Toolet 
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#ifndef ST_MAINWINDOW_HPP
#define ST_MAINWINDOW_HPP

#include <QMainWindow>
#include "ui_mainwindow.h"

namespace Starstructor { namespace GUI {

class STMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    STMainWindow(QWidget* parent = nullptr);
    STMainWindow(const STMainWindow& other) = delete;
    STMainWindow(STMainWindow&& other) = delete;
    STMainWindow& operator=(const STMainWindow& other) = delete;

private:
    Ui::ApplicationWindow m_mainWindow;;

};

}

}

#endif // ST_MAINWINDOW_HPP
