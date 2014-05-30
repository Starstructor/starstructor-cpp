/*
Starstructor, the Starbound Toolset 
Copyright (C) 2013-2014 Chris Stamford
Licensed under terms of The MIT License (MIT)

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com
*/

#include "core/object/stasset.hpp"

namespace Starstructor { namespace Core {

Asset::Asset(const QString& path)
    : Parseable(path)
{
}

Asset::~Asset()
{ 
}

}

}