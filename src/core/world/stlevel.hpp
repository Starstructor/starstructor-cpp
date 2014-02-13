/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
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