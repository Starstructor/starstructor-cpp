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

#include "core/stjsonfile.hpp"

namespace Starstructor { namespace Core {

class Level 
{
public:
    Level() = delete;
    Level(const QString& path);
    virtual ~Level();
    
    JsonFile* getJsonFile();

protected:
    JsonFile m_json;
};

}

}

#endif // STLEVEL_HPP