/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#ifndef STJSONFILE_HPP
#define STJSONFILE_HPP

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

#include <string>

namespace Starstructor { namespace Core {

class JsonFile final
{
public:
    JsonFile(const std::string& path);
    ~JsonFile();

    const std::string& getFilePath() const;
    const QJsonDocument& getJsonDocument() const;

    void loadFromFile(const std::string& path);
    void loadFromRawData(const QByteArray& rawData);

private:
    QJsonDocument m_jsonDocument;
    std::string m_path;
};

}

}

#endif // STJSONFILE_HPP