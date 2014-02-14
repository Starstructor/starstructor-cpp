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

namespace Starstructor { namespace Utility {

DirectoryServices::DirectoryServices(const QDir& path, Utility::Logger* logger)
    : m_logger{ logger }
{
    const QList<QString> filters{ "object", "material", "npc",
        "structure", "dungeon", "world", "shipworld" };

    if (m_logger)
    {
        QString msg{ "Scanning for all files in " + path.path() 
            + " with extensions:" };

        for (const auto& filter : filters)
        {
            msg += " ." + filter;
        }

        m_logger->writeLine(msg);
    }

    Timer timer{ TimerPrecision::MILLISECONDS };

    m_files = getDirContents_r(path, filters);

    if (m_logger)
    {
        m_logger->writeLine("Scanning complete in " 
            + QString::number(timer.getTime()) + "ms. " 
            + QString::number(m_files.count()) + " files found.");
    }
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

    return std::move(getFilteredList(filters));
}

QList<QFileInfo> DirectoryServices::getFilteredList(const QList<QString>& filters) const
{
    QList<QFileInfo> newList{};

    for (const auto& file : m_files)
    { 
        const QString suffix = file.suffix();

        for (const auto& filter : filters)
        {
            if (suffix == filter)
                newList.push_back(file.filePath());
        }
    }

    return std::move(newList);
}

QList<QFileInfo> DirectoryServices::getDirContents_r(const QDir& directory,
    const QList<QString>& filters) const
{
    const QList<QFileInfo> fileList{ directory.entryInfoList(
        QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot) };

    QList<QFileInfo> matchingFiles{};

    for (const auto& file : fileList)
    {
        if (file.isDir())
        {
            const auto recMatchingFiles = getDirContents_r(
                QDir{ file.filePath() }, filters);

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