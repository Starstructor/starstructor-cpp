/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#ifndef STDIRECTORYSERVICES_HPP
#define STDIRECTORYSERVICES_HPP

#include "utility//stlogger.hpp"

#include <QDir>
#include <QList>
#include <QFileInfo>

namespace Starstructor { namespace Utility {

enum class DirectoryServicesFlag
{
    OBJECT      = 1,
    MATERIAL    = 1 << 1,
    NPC         = 1 << 2,
    STRUCTURE   = 1 << 3,
    DUNGEON     = 1 << 4,
    WORLD       = 1 << 5,
    SHIPWORLD   = 1 << 6,
};

Q_DECLARE_FLAGS(DirectoryServicesFlags, DirectoryServicesFlag);
Q_DECLARE_OPERATORS_FOR_FLAGS(DirectoryServicesFlags);

class DirectoryServices final
{
public:

    DirectoryServices() = delete;
    DirectoryServices(const QDir& path, Utility::Logger* logger = nullptr);

    DirectoryServices(DirectoryServices&& other) = default;
    DirectoryServices& operator=(DirectoryServices&& other) = default;

    QList<QFileInfo> getFiles(const DirectoryServicesFlags flags = 
        DirectoryServicesFlag::OBJECT   | DirectoryServicesFlag::MATERIAL |
        DirectoryServicesFlag::NPC      | DirectoryServicesFlag::STRUCTURE |
        DirectoryServicesFlag::DUNGEON  | DirectoryServicesFlag::WORLD |
        DirectoryServicesFlag::SHIPWORLD) const;

private:
    QList<QFileInfo> getFilteredList(const QList<QString>& filters) const;
    QList<QFileInfo> getDirContents_r(const QDir& directory,
        const QList<QString>& filters) const;

    QList<QFileInfo> m_files;
    Utility::Logger* m_logger;
};

}

}

#endif // STDIRECTORYSERVICES_HPP