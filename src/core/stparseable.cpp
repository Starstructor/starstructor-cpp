/*
Starstructor, the Starbound Toolset 
Copyright (C) 2013-2014 Chris Stamford
Licensed under terms of The MIT License (MIT)

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com
*/

#include "core/stparseable.hpp"

namespace Starstructor { namespace Core {

Parseable::Parseable(const QString& path)
    : m_json{ path }
{}

Parseable::~Parseable()
{}

JsonFile* Parseable::getJsonFile()
{
    return &m_json;
}

}

}
