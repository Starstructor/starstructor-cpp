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
#include "core/world/stworldfile.hpp"
#include "core/stjsonfile.hpp"

#include <QApplication>
#include <QDir>
#include <QFileInfo>
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

	while (window.isVisible())
    {
        try
        {
            application.processEvents(QEventLoop::ProcessEventsFlag::AllEvents, MAX_LOCK_TIME_MS);
        }
		catch (const Starstructor::Exception& ex)
        {
            std::cout << ex.what() << std::endl;
            break;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Unrecoverable STL exception: " << ex.what() << std::endl;
            break;
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
            Starstructor::Core::JsonFile* const json{ world.getJsonFile() };
            const QJsonDocument doc = json->getJsonDocument();

            QJsonObject obj1{ doc.object() };
            QJsonValue val1{ obj1.value("blockKey") };
            qDebug() << val1;
        }
        catch (const Starstructor::FileNotFoundException& ex)
        {
            std::cout << ex.what() << std::endl;
        }
        catch (const Starstructor::JsonInvalidFormat& ex)
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