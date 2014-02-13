/*
Starstructor, the Starbound Toolet 
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#include "stexception.hpp"
#include "gui/stmainwindow.hpp"
#include "utility/sttimer.hpp"

#include <QApplication>
#include <QDir>
#include <QFileInfo>
#include <QDebug>

#include <exception>

int main(int argc, char* argv[])
{
    using namespace Starstructor;

    QApplication application{ argc, argv };

    GUI::MainWindow window{};
    window.show();

    int loopCount{};
    Utility::Timer timer{ Utility::TimerPrecision::MILLISECONDS };
    
	while (window.isVisible())
    {
        try
        {
            application.processEvents(QEventLoop::ProcessEventsFlag::AllEvents);
            ++loopCount;

            const auto time = timer.getTime();

            if (time > 500)
            {
                qDebug() << loopCount << " iterations in" << time << "ms";
                loopCount = 0;
                timer.reset();
            }
        }
        catch (const Starstructor::Exception& ex)
        {
            qDebug() << ex.what();
            break;
        }
        catch (const std::exception& ex)
        {
            qDebug() << "Unrecoverable STL exception: " << ex.what();
            break;
        }
    }
}