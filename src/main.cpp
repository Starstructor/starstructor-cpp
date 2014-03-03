/*
Starstructor, the Starbound Toolset 
Copyright (C) 2013-2014 Chris Stamford
Licensed under terms of The MIT License (MIT)

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com
*/

#include "stexception.hpp"
#include "gui/stmainwindow.hpp"
#include "utility/sttimer.hpp"
#include "utility/stlogger.hpp"
#include "utility/stdirectoryservices.hpp"
#include "core/stassetmanager.hpp"
#include "core/world/stworldfile.hpp"

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

    MainWindow window{};
    window.show();

    const QString logPath{ application.applicationDirPath() + "/logs/" };
    const QString fileName{ 
        QDateTime::currentDateTime().toString("MM-dd-yyyy_HH-mm-ss")
        + "_starstructor.txt" };

    Utility::Logger log{ logPath + fileName };

    const QString path{ "A:/Development/starbound/" };
    Utility::DirectoryServices dirServices{ path, log };

    Core::AssetManager assetManager{ dirServices, log };

    auto worldList = dirServices.getFiles(Utility::DirectoryServicesFlag::WORLD);

    Utility::Timer frameTimer{};
    int frames{};

	while (window.isVisible())
    {
        try
        {
            application.processEvents(QEventLoop::ProcessEventsFlag::AllEvents);
            window.frame();

            ++frames;
            const auto frameTime = frameTimer.getTime();

            if (frameTime >= 1000)
            {
                log.writeLine(QString::number(frames) + " frames in " +
                    QString::number(frameTime) + "ms.");

                frames = 0;
                frameTimer.reset();
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