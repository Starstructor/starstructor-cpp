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

#include <QApplication>
#include <QDir>
#include <QFileInfo>
#include <QDebug>

#include <exception>
#include <thread>

using namespace Starstructor;

void scan(const Utility::DirectoryServices& services);

int main(int argc, char* argv[])
{
    QApplication application{ argc, argv };

    GUI::MainWindow window{};
    window.show();

    Utility::Logger log{ R"(C:/test.txt)" };

    const QString path{ R"(A:/Development/starbound/assets/)" };

    using Utility::DirectoryServices;
    
    DirectoryServices dirServices{ path, &log };

    void (DirectoryServices::*func)(const QDir&) 
        = &DirectoryServices::rescanPath;

    std::thread thread1{ func, std::ref(dirServices), path };
    std::thread thread2{ func, std::ref(dirServices), path };
    std::thread thread3{ func, std::ref(dirServices), path };
    std::thread thread4{ func, std::ref(dirServices), path };
    std::thread thread5{ func, std::ref(dirServices), path };

    auto all = dirServices.getFiles();

    auto objects = dirServices.getFiles(Utility::DirectoryServicesFlag::OBJECT);

    auto worlds = dirServices.getFiles(
        Utility::DirectoryServicesFlag::DUNGEON |
        Utility::DirectoryServicesFlag::WORLD |
        Utility::DirectoryServicesFlag::STRUCTURE |
        Utility::DirectoryServicesFlag::SHIPWORLD);

    int loopCount{};
    Utility::Timer timer{ Utility::TimerPrecision::MILLISECONDS };

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