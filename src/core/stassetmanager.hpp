/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#ifndef STASSETMANAGER_HPP
#define STASSETMANAGER_HPP

#include <QVector>
#include <QString>
#include <QHash>
#include <QDir>

#include <memory>

namespace Starstructor { namespace Core {

class Logger; class Asset;

class AssetManager
{
public:
    AssetManager() = delete;
    AssetManager(const QString& path, 
        const QVector<QString> filters = { "object", "npc", "material" },
        Logger* const log = nullptr);

private:
    QVector<QFileInfo> getDirContents_r(const QDir& directory,
        const QVector<QString>& filters);

    QHash<QString, Asset*> m_assetMap;
    Logger* m_logger;
};

}

}

#endif // STASSETMANAGER_HPP