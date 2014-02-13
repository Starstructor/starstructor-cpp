/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#ifndef STASSET_HPP
#define STASSET_HPP

#include <QString>

namespace Starstructor { namespace Core {

class Asset
{
public:
    Asset() = delete;
    Asset(const QString& path);

private:
    QString m_fileName = "undefined";
};

}

}

#endif // STASSET_HPP