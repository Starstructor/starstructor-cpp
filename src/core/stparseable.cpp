/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#include "core/stparseable.hpp"

namespace Starstructor { namespace Core {

Parseable::Parseable(const QString& path)
: m_json{ path }
{ }

Parseable::~Parseable()
{ }

JsonFile* Parseable::getJsonFile()
{
    return &m_json;
}

}

}
