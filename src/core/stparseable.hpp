/*
Starstructor, the Starbound Toolset 
Copyright (C) 2013-2014 Chris Stamford
Licensed under terms of The MIT License (MIT)

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com
*/

#ifndef STPARSEABLE_HPP
#define STPARSEABLE_HPP

#include "core/stjsonfile.hpp"

#include <QString>

namespace Starstructor { namespace Core {

class Parseable
{
public:
    virtual ~Parseable() = 0;

    JsonFile* getJsonFile();

    Parseable(const Parseable& other) = delete;
    Parseable& operator=(const Parseable& other) = delete;

protected:
    explicit Parseable(const QString& path);

    JsonFile m_json;
};

}

}

#endif // STPARSEABLE_HPP
