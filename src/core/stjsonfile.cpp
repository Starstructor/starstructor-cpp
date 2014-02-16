/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#include "core/stjsonfile.hpp"
#include "stexception.hpp"

#include <QFile>
#include <QFileInfo>
#include <QRegularExpression>

namespace Starstructor { namespace Core {

JsonFile::JsonFile(const QString& path)
    : m_filePath{ path }
{
    loadFromFile(path);
}

JsonFile::~JsonFile()
{}

const QString& JsonFile::getFilePath() const
{
    return m_filePath;
}

const QJsonDocument& JsonFile::getJsonDocument() const
{
    return m_jsonDocument;
}

void JsonFile::loadFromFile(const QString& path)
{
    QFile file{ path };

    if (!file.open(QIODevice::ReadOnly))
        throw FileNotFoundException{ "Unable to open file at " + path };

    const QByteArray rawData{ file.readAll() };
    file.close();

    try
    {
        loadFromRawData(rawData);
    }
    catch (const JsonInvalidFormat& ex)
    {
        const QString fileName{ QFileInfo{ file }.fileName() };
        throw JsonInvalidFormat{ ex.message() + " from file " + fileName };
    }
}

void JsonFile::loadFromRawData(const QByteArray& rawData)
{
    QJsonParseError error{};

    m_jsonDocument = QJsonDocument::fromJson(JsonFile::stripComments(rawData), 
        &error);

    if (error.error != QJsonParseError::NoError)
        throw JsonInvalidFormat{ error.errorString() };

    else if (m_jsonDocument.isNull())
        throw JsonInvalidFormat{ "Parsed document is null - empty file?" };
}

QByteArray JsonFile::stripComments(const QByteArray& rawData)
{
    QString formattedJson{ rawData };

    // Strip c++-style comments
    formattedJson.replace(QRegularExpression{ R"(//(.*?)\n)" }, "");

    /* Strip c-style comments */
    formattedJson.replace(QRegularExpression{ R"(/\*(.*)\*/)" }, "");

    return formattedJson.toUtf8();
}

}

}