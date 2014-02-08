/*
Starstructor, the Starbound Toolet 
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#ifndef STMAINWINDOW_HPP
#define STMAINWINDOW_HPP

#include <QMainWindow>
#include "ui_mainwindow.h"

namespace Starstructor { namespace GUI {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    MainWindow(const MainWindow& other) = delete;
    MainWindow(MainWindow&& other) = delete;
    MainWindow& operator=(const MainWindow& other) = delete;

private:
    Ui::ApplicationWindow m_mainWindow;;

};

}

}

#endif // STMAINWINDOW_HPP
