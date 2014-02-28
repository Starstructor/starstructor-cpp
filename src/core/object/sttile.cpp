/*
Starstructor, the Starbound Toolset 
Copyright (C) 2013-2014 Chris Stamford
Licensed under terms of The MIT License (MIT)

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com
*/

#include "core/object/sttile.hpp"
#include "stexception.hpp"

#include <QtOpenGL/qgl.h>
#include <QFileInfo>
#include <QDir>

namespace Starstructor { namespace Core {

Tile::Tile(const QString& path) : Asset(path)
{
    const QJsonDocument& doc = m_json.getJsonDocument();

    try
    {
        auto obj = doc.object();

        m_info.reset(new TileInfo{});
        m_info->id = obj.find("materialId").value().toInt();
        m_info->name = obj.find("materialName").value().toString();
        m_info->platform = obj.find("platform").value().toBool();

        if (m_info->name.isNull())
            throw JsonInvalidFormatException{ "No materialName defined" };

        if (!m_info->platform)
        {
            const unsigned int variants = obj.find("variants").value().toInt();
            const bool multiColoured = obj.find("multicolored").value().toBool();
            const QString framesName = obj.find("frames").value().toString();

            if (framesName.isNull())
                throw JsonInvalidFormatException{ "No frames defined" };

            const QString framesPath = 
                QFileInfo{ path }.dir().absoluteFilePath(framesName);

            m_matRenderInfo.reset(
                new MaterialRenderInfo{ variants, multiColoured, framesPath });
        }
        else
        {

        }
    }
    catch (const Exception& ex)
    {
        throw AssetLoadException{ ex.message() + " in file " + path + " when "
            + "deserialising tile" };
    }
}

MaterialRenderInfo::MaterialRenderInfo(const unsigned int& variants, 
    const bool& multiColoured, const QString& framesPath)
    : m_variants{ variants }, m_multiColoured{ multiColoured }
{
    m_image.reset(new QImage{ framesPath });

    if (m_image->isNull())
        throw FileNotFoundException{ "Unable to open file at " + framesPath };
}

const QRectF& MaterialRenderInfo::tile(const unsigned int& variant,
    const unsigned int& colour) const
{
    return QRectF{};
}

}

}