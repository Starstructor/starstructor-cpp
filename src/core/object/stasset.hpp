/*
Starstructor, the Starbound Toolset 
Copyright (C) 2013-2014 Chris Stamford
Licensed under terms of The MIT License (MIT)

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com
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
    explicit Asset(const QString& path);
};

}

}

#endif // STASSET_HPP
