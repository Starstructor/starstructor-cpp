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
#include "utility/stlogger.hpp"
#include "utility/stdirectoryservices.hpp"
#include "core/stassetmanager.hpp"

#include <QApplication>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>

#include <exception>
#include <thread>

using namespace Starstructor;

int main(int argc, char* argv[])
{
    QApplication application{ argc, argv };

    GUI::MainWindow window{};
    window.show();

    const QString logPath = application.applicationDirPath() + "/logs/";
    const QString fileName{ 
        QDateTime::currentDateTime().toString("MM-dd-yyyy_HH-mm-ss")
        + "_starstructor.txt" };

    Utility::Logger log{ logPath + fileName };

    const QString path{ "A:/Development/starbound/assets/" };
    Utility::DirectoryServices dirServices{ path, &log };

    Core::AssetManager assetManager{ &dirServices, &log };

    int loopCount{};
    Utility::Timer timer{};

	while (window.isVisible())
    {
        try
        {
            application.processEvents(QEventLoop::ProcessEventsFlag::AllEvents);
            ++loopCount;

            const auto time = timer.getTime();

            if (time >= 500)
            {
                log.writeLine(QString::number(loopCount) + " iterations in " 
                    + QString::number(time) + "ms");

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