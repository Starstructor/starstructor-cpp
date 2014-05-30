/*
Starstructor, the Starbound Toolset 
Copyright (C) 2013-2014 Chris Stamford
Licensed under terms of The MIT License (MIT)

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com
*/

#include "core/world/stlevel.hpp"

namespace Starstructor { namespace Core {

Level::Level(const QString& path)
    : Parseable(path)
{
}

Level::~Level()
{
    
}

}

}