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
    QFile file{ path.c_str() };

    if (!file.open(QIODevice::ReadOnly))
        throw Exception::FileNotFoundException("Unable to open file " + path);

    const QByteArray rawData = file.readAll();
    file.close();

    m_jsonDocument = QJsonDocument::fromJson(rawData);

    if (m_jsonDocument.isNull())
        throw Exception::JsonInvalidFormat("Attempted to read Json from " + path + ", but was null");
}

JsonFile::~JsonFile()
{ }

const std::string& JsonFile::getFilePath() const
{
    return m_path;
}

const QJsonDocument& JsonFile::getJsonDocument() const
{
    return m_jsonDocument;
}

void JsonFile::setJsonDocument(const QJsonDocument& document)
{
    m_jsonDocument = document;
}

}

}