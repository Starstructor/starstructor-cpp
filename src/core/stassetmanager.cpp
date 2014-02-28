/*
Starstructor, the Starbound Toolset 
Copyright (C) 2013-2014 Chris Stamford
Licensed under terms of The MIT License (MIT)

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com
*/

#include "core/stassetmanager.hpp"

#include "stexception.hpp"
#include "utility/sttimer.hpp"
#include "core/object/stobject.hpp"
#include "core/object/stmaterial.hpp"
#include "core/object/stnpc.hpp"

#include <QFileInfo>

namespace Starstructor { namespace Core {

AssetManager::AssetManager(const Utility::DirectoryServices& services, 
    Utility::Logger& logger)
    : m_logger{ &logger }
{
    auto assetFileList = services.getFiles(
        Utility::DirectoryServicesFlag::OBJECT   | 
        Utility::DirectoryServicesFlag::MATERIAL |
        Utility::DirectoryServicesFlag::NPC);

    const int assetsFound{ assetFileList.count() };
    int assetsLoaded{ 0 };

    m_logger->writeLine(QString::number(assetsFound) 
        + " assets to be loaded.");

    Utility::Timer loadTimer{};

    for (const auto& file : assetFileList)
    {
        const QString name{ file.fileName() };

        if (m_assetMap.find(name) != m_assetMap.end())
        {
            m_logger->writeLine("Failed to load asset " + name
                + " because it already exists in the asset map.");

            continue;
        }

        const QString assetType{ file.suffix()} ;

        try
        {
            if (assetType == "object")
                m_assetMap[name].reset(new Object{ file.filePath() });

            else if (assetType == "material")
                m_assetMap[name].reset(new Material{ file.filePath() });

            else if (assetType == "npc")
                m_assetMap[name].reset(new NPC{ file.filePath() });
        }
        catch (const Exception& ex)
        {
            m_logger->writeLine(ex);
            continue;
        }

        ++assetsLoaded;
        m_logger->writeLine("Successfully loaded asset " + name);
    }

    m_logger->writeLine(QString::number(assetsLoaded) + " assets loaded in "
        + QString::number(loadTimer.getTime()) + " ms, "
        + QString::number(assetsFound - assetsLoaded) + " assets invalid.");
}

}

}
