/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#include "core/object/stasset.hpp"

namespace Starstructor { namespace Core {

Asset::Asset(const QString& path)
    : Parseable{ path }
{}

Asset::~Asset()
{}

}

}