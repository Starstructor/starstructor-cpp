/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#ifndef STWORLDFILE_HPP
#define STWORLDFILE_HPP

#include "core/stjsonfile.hpp"

namespace Starstructor { namespace Core {

class WorldFile 
{
public:
    WorldFile(const std::string& path);
    virtual ~WorldFile();
    
    JsonFile* getJsonFile();

protected:
    JsonFile m_json;
};

}

}

#endif // STWORLDFILE_HPP