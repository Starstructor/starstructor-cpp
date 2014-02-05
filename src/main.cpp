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
#include <QList>
#include <QString>
#include <QDebug>


QList<QString> getDirContents_r(QDir directory, const QList<QString> filters);

int main(int argc, char* argv[])
{
	QApplication application{argc, argv};

    Starstructor::MainWindow window;
    window.show();

    auto dirContents = getDirContents_r(
        QDir{ Starstructor::SB_DIRECTORY }, 
        QList<QString>{ "object", "material" });

    qDebug() << "Parsed elements:  " + QString::number(dirContents.count());

	return application.exec();
}

// Recursively iterate through a given directory
// Optionally applies the given file extension filters
QList<QString> getDirContents_r(QDir directory, const QList<QString> filters = {})
{
    const QList<QFileInfo> fileList{ directory.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot) };
    QList<QString> matchingFiles{};

    // Recursively iterate through directories
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
                if (suffix == filter)
                {
                    matchingFiles.push_back(file.filePath());
                    qDebug() << file.filePath();
                }
            }
        }
    }

    return matchingFiles;
}
