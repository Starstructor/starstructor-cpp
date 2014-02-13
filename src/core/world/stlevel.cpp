/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#include "core/world/stLevel.hpp"

namespace Starstructor { namespace Core {

Level::Level(const QString& path)
    : m_json{ path }
{}

Level::~Level()
{}

JsonFile* Level::getJsonFile()
{
    return &m_json;
}

}

}