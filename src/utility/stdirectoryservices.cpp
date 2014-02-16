/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#include "utility/stdirectoryservices.hpp"
#include "utility/sttimer.hpp"

using std::lock_guard;
using std::mutex;

namespace Starstructor { namespace Utility {

DirectoryServices::DirectoryServices(const QDir& path, Utility::Logger& logger)
    : m_logger{ &logger }, m_readWriteMutex{}
{
    rescanPath(path);
}

DirectoryServices::DirectoryServices(const QString& path, Utility::Logger& logger)
    : DirectoryServices(QDir{ path }, logger)
{}

void DirectoryServices::rescanPath(const QDir& path)
{
    const QList<QString> filters{ "object", "material", "npc",
        "structure", "dungeon", "world", "shipworld" };

    QString msg{ "Scanning for all files in " + path.path()
        + " with extensions:" };

    for (const auto& filter : filters)
    {
        msg += " ." + filter;
    }

    m_logger->writeLine(msg);

    Timer timer{};

    const auto newFiles = getDirContents_r(path, filters);

    lock_guard<mutex> lock{ m_readWriteMutex };
    m_files = newFiles;

    m_logger->writeLine("Scanning complete in "
        + QString::number(timer.getTime()) + "ms. "
        + QString::number(m_files.count()) + " files found.");
}

void DirectoryServices::rescanPath(const QString& path)
{
    rescanPath(QDir{ path });
}

QList<QFileInfo> DirectoryServices::getFiles(const DirectoryServicesFlags flags) const
{
    // If the caller wants everything, just copy the list, rather than
    // going through the hassle of applying filters to it
    if (flags &
        DirectoryServicesFlag::OBJECT   & DirectoryServicesFlag::MATERIAL &
        DirectoryServicesFlag::NPC      & DirectoryServicesFlag::STRUCTURE &
        DirectoryServicesFlag::DUNGEON  & DirectoryServicesFlag::WORLD &
        DirectoryServicesFlag::SHIPWORLD)
    {
        lock_guard<mutex> lock{ m_readWriteMutex };
        return m_files;
    }

    QList<QString> filters{};

    if (flags & DirectoryServicesFlag::OBJECT)
        filters.push_back("object");

    if (flags & DirectoryServicesFlag::MATERIAL)
        filters.push_back("material");

    if (flags & DirectoryServicesFlag::NPC)
        filters.push_back("npc");

    if (flags & DirectoryServicesFlag::STRUCTURE)
        filters.push_back("structure");

    if (flags & DirectoryServicesFlag::DUNGEON)
        filters.push_back("dungeon");

    if (flags & DirectoryServicesFlag::WORLD)
        filters.push_back("world");

    if (flags & DirectoryServicesFlag::SHIPWORLD)
        filters.push_back("shipworld");

    return getFilteredList(filters);
}

QList<QFileInfo> DirectoryServices::getFilteredList(const QList<QString>& filters) const
{
    QList<QFileInfo> newList{};
    lock_guard<mutex> lock{ m_readWriteMutex };

    for (const auto& file : m_files)
    { 
        const QString suffix{ file.suffix() };

        for (const auto& filter : filters)
        {
            if (suffix == filter)
                newList.push_back(file.filePath());
        }
    }

    return newList;
}

QList<QFileInfo> DirectoryServices::getDirContents_r(const QDir& directory,
    const QList<QString>& filters) const
{
    const QList<QFileInfo> fileList{ directory.entryInfoList(
        QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot, QDir::DirsFirst) };

    QList<QFileInfo> matchingFiles{};

    for (const auto& file : fileList)
    {
        if (file.isDir())
        {
            const auto recMatchingFiles = getDirContents_r(
                QDir{ file.absoluteFilePath() }, filters);

            if (!recMatchingFiles.isEmpty())
                matchingFiles += recMatchingFiles;
        }
        else
        {
            const QString suffix = file.suffix();

            for (const auto& filter : filters)
            {
                if (suffix == filter)
                    matchingFiles.push_back(file);
            }
        }
    }

    return matchingFiles;
}

}

}
