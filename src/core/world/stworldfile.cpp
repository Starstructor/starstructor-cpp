/*
Starstructor, the Starbound Toolset 
Copyright (C) 2013-2014 Chris Stamford
Licensed under terms of The MIT License (MIT)

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com
*/

#include "core/world/stworldfile.hpp"
#include "stexception.hpp"

#include <QFile>

namespace Starstructor { namespace Core {

WorldFile::WorldFile(const QString& path)
{
    QFile file{ path };

    if (!file.open(QIODevice::ReadOnly))
        throw FileNotFoundException{ "Unable to open world file at " + path };

    QByteArray rawData{ file.readAll() };
}

}

}