/*
Starstructor, the Starbound Toolset 
Copyright (C) 2013-2014 Chris Stamford
Licensed under terms of The MIT License (MIT)

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com
*/

#ifndef STJSONFILE_HPP
#define STJSONFILE_HPP

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QString>

namespace Starstructor { namespace Core {

class JsonFile final
{
public:
    explicit JsonFile(const QString& path);
    ~JsonFile();

    const QString& getFilePath() const;
    const QJsonDocument& getJsonDocument() const;

    void loadFromFile(const QString& path);
    void loadFromRawData(const QByteArray& rawData);
    static QByteArray stripComments(const QByteArray& rawData);

private:
    QJsonDocument m_jsonDocument;
    QString m_filePath;
};

}

}

#endif // STJSONFILE_HPP