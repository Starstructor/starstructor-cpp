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

#include "core/stparseable.hpp"

#include <QString>

namespace Starstructor { namespace Core {

class Asset : public Parseable
{
public:
    virtual ~Asset() = 0;

protected:
    Asset(const QString& path);
};

}

}

#endif // STASSET_HPP