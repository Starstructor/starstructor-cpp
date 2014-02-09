/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#include "core/stjsonfile.hpp"
#include "exception/stexception.hpp"

#include <QFile>

namespace Starstructor { namespace Core {

JsonFile::JsonFile(const std::string& path)
    :m_path {path}
{
    loadFromFile(path);
}

JsonFile::~JsonFile()
{}

const std::string& JsonFile::getFilePath() const
{
    return m_path;
}

const QJsonDocument& JsonFile::getJsonDocument() const
{
    return m_jsonDocument;
}

void JsonFile::loadFromFile(const std::string& path)
{
    QFile file{ path.c_str() };

    if (!file.open(QIODevice::ReadOnly))
        throw Exception::FileNotFoundException("Unable to open file " + path);

    const QByteArray rawData = file.readAll();
    file.close();

    try
    {
        loadFromRawData(rawData);
    }
    catch (const Exception::JsonInvalidFormat& ex)
    {
        throw Exception::JsonInvalidFormat(ex.message() + " from file " + path);
    }
}

void JsonFile::loadFromRawData(const QByteArray& rawData)
{
    m_jsonDocument = QJsonDocument::fromJson(rawData);

    if (m_jsonDocument.isNull())
        throw Exception::JsonInvalidFormat("JSON format invalid");
}

}

}
