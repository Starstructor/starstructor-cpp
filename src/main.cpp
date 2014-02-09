/*
Starstructor, the Starbound Toolet 
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#include "gui/stmainwindow.hpp"
#include "exception/stexception.hpp"
#include "core/world/stworldfile.hpp"

#include <QApplication>
#include <QDir>
#include <QFileInfo>
#include <QJsonObject>
#include <QDebug>

#include <exception>
#include <iostream>

const QString TEST_ASSET_DIR{ R"(A:\Development\starboundgit\master\assets)" };
const int MAX_LOCK_TIME_MS{ 5 };

void testLoadingStuff();
QList<QString> getDirContents_r(const QDir& directory, const QList<QString>& filters);

int main(int argc, char* argv[])
{
    QApplication application{ argc, argv };

    Starstructor::GUI::MainWindow window{};
    window.show();

    testLoadingStuff();

    bool running{ true };

    while (running)
    {
        try
        {
            application.processEvents(QEventLoop::ProcessEventsFlag::AllEvents, MAX_LOCK_TIME_MS);

            if (!window.isVisible())
                throw Starstructor::Exception::Exception{ "test throw - closing application" };
        }
        catch (const Starstructor::Exception::Exception& ex)
        {
            std::cout << ex.what() << std::endl;
            running = false;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Unrecoverable STL exception: " << ex.what() << std::endl;
            running = false;
        }
    }
}

void testLoadingStuff()
{
    std::list<std::string> filesToLoad{ "test1.png", "F:\\breakme", "????" };

    auto matches = getDirContents_r(QDir{ TEST_ASSET_DIR }, QList<QString> { "dungeon" });

    for (const auto& path : matches)
    {
        filesToLoad.push_back(path.toStdString());
    }

    for (const auto& path : filesToLoad)
    {
        try
        {
            Starstructor::Core::WorldFile world{ path };

            const QJsonDocument * const doc{ &(world.m_json.getJsonDocument()) };
            QJsonObject obj1{ doc->object() };
            QJsonValue val1{ obj1.value("blockKey") };
            qDebug() << val1;

        }
        catch (const Starstructor::Exception::FileNotFoundException& ex)
        {
            std::cout << ex.what() << std::endl;
        }
        catch (const Starstructor::Exception::JsonInvalidFormat& ex)
        {
            std::cout << ex.what() << std::endl;
        }
    }
}

// Recursively iterate through a given directory
// Optionally applies the given file extension filters
QList<QString> getDirContents_r(const QDir& directory, const QList<QString>& filters = {})
{
    const QList<QFileInfo> fileList{ directory.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot) };
    QList<QString> matchingFiles{};

    for (const auto& file : fileList)
    {
        if (file.isDir())
        {
            const auto recMatchingFiles = getDirContents_r(QDir{ file.filePath() }, filters);        
            if (!recMatchingFiles.isEmpty()) matchingFiles.append(recMatchingFiles);
        }
        else
        {
            const QString suffix = file.suffix();

            for (const auto& filter : filters)
            {
                if (suffix == filter) matchingFiles.push_back(file.filePath());
            }
        }
    }

    return matchingFiles;
}