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

#include <QApplication>

#include <exception>
#include <iostream>

int main(int argc, char* argv[])
{
    QApplication application{ argc, argv };

    Starstructor::GUI::MainWindow window{};
    window.show();

    bool running{ true };

    while (running)
    {
        try
        {
            application.processEvents();

            if (!window.isVisible())
                throw Starstructor::Except::Exception{ "test throw - closing application" };
        }
        catch (const Starstructor::Except::Exception& ex)
        {
            std::cout << ex << std::endl;
            running = false;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Unrecoverable STL exception: " << ex.what() << std::endl;
            running = false;
        }
    }
}

/*// Recursively iterate through a given directory
// Optionally applies the given file extension filters
QList<QString> getDirContents_r(QDir directory, const QList<QString> filters = {})
{
    const QList<QFileInfo> fileList{ directory.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot) };
    QList<QString> matchingFiles{};

    for (const auto& file : fileList)
    {
        if (file.isDir())
        {
            const auto recMatchingFiles = getDirContents_r(QDir{ file.filePath() }, filters);        
            if (recMatchingFiles.count() != 0) matchingFiles.append(recMatchingFiles);
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
}*/
