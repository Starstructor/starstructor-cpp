/*
Starstructor, the Starbound Toolet 
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#include "gui/mainwindow.hpp"
#include "constants.hpp"

#include <QApplication>
#include <QDir>

#include <string>
#include <iostream>
#include <list>
#include <algorithm>

using std::string; 
using std::list;

list<string> getDirContents_r(QDir directory, const list<string> filters);

int main(int argc, char* argv[])
{
	QApplication application{argc, argv};

    Starstructor::MainWindow window;
    window.show();

    list<string> dirContents = getDirContents_r(
        QDir{ Starstructor::SB_DIRECTORY }, 
        list<string>{ "object", "material" });

	return application.exec();
}

// Recursively iterate through a given directory
// Optionally applies the given file extension filters
list<string> getDirContents_r(QDir directory, const list<string> filters = {})
{
    const list<QFileInfo> fileList{ directory.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot).toStdList() };
    list<string> matchingFiles{};

    // Recursively iterate through directories
    for (const QFileInfo file : fileList)
    {
        if (file.isDir())
        {
            matchingFiles.merge(getDirContents_r(QDir{ file.filePath() }, filters));
        }
        else
        {
            const string suffix = file.suffix().toStdString();

            for (string filter : filters)
            {
                if (suffix == filter)
                {
                    const string path = file.filePath().toStdString();
                    matchingFiles.push_back(path);
                    std::cout << path << std::endl;
                }
            }
        }
    }

    return matchingFiles;
}
