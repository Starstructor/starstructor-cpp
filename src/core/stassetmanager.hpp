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

#include "utility/stlogger.hpp"
#include "utility/stdirectoryservices.hpp"
#include "core/object/stasset.hpp"

#include <QVector>
#include <QString>
#include <QHash>
#include <QDir>

#include <memory>

namespace Starstructor { namespace Core {

class AssetManager
{
public:
    AssetManager() = delete;
    AssetManager(Utility::DirectoryServices* services, 
        Utility::Logger* logger = nullptr);

private:
    QHash<QString, std::unique_ptr<Asset>> m_assetMap;
    Utility::Logger* m_logger;
};

}

}

#endif // STASSETMANAGER_HPP