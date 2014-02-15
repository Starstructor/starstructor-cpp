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

#include "ststlspecialisation.hpp"
#include "utility/stlogger.hpp"
#include "utility/stdirectoryservices.hpp"
#include "core/object/stasset.hpp"

#include <QHash>
#include <QString>

#include <unordered_map>
#include <memory>

namespace Starstructor { namespace Core {

class AssetManager
{
public:
    AssetManager() = delete;
    AssetManager(Utility::DirectoryServices* services, 
        Utility::Logger* logger = nullptr);

private:
    // QHash doesn't like unique_ptr (probably lack of move semantics),
    // so use an unordered_map here instead
    std::unordered_map<QString, std::unique_ptr<Asset>> m_assetMap;
    Utility::Logger* m_logger;
};

}

}

#endif // STASSETMANAGER_HPP