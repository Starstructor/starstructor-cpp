/*
Starstructor, the Starbound Toolset 
Copyright (C) 2013-2014 Chris Stamford
Licensed under terms of The MIT License (MIT)

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com
*/

#ifndef STLEVEL_HPP
#define STLEVEL_HPP

#include "core/stparseable.hpp"

namespace Starstructor { namespace Core {

class Level : public Parseable
{
public:
    virtual ~Level() = 0;

protected:
    Level(const QString& path);
};

}

}

#endif // STLEVEL_HPP