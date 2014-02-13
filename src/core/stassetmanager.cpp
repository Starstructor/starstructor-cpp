/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#include "stexception.hpp"
#include "utility/stlogger.hpp"
#include "core/stassetmanager.hpp"
#include "core/object/stasset.hpp"
#include "core/object/stobject.hpp"
#include "core/object/stmaterial.hpp"
#include "core/object/stnpc.hpp"

#include <QFileInfo>

using std::unique_ptr;

namespace Starstructor { namespace Core {

AssetManager::AssetManager(const QString& path, Logger* const logger,
    const QVector<QString> filters)
: m_logger{ logger }
{
    for (const auto& file : getDirContents_r(QDir{ path }, filters))
    {
        try
        {
            const QString fileName = file.fileName();

            if (!m_assetMap.contains(fileName))
            {
                const QString suffix = file.suffix();

                if (suffix == "object")
                {
                    //m_assetMap[fileName]
                     //   = new Object{ file.filePath() };
                }
            }
        }
        catch (const FileNotFoundException& ex)
        {

        }
    }
}

QVector<QFileInfo> AssetManager::getDirContents_r(const QDir& directory,
    const QVector<QString>& filters)
{
    const QVector<QFileInfo> fileList{ directory.entryInfoList(
        QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot).toVector() };

    QVector<QFileInfo> matchingFiles{};

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