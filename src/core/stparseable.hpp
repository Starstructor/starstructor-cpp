/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#ifndef STPARSEABLE_HPP
#define STPARSEABLE_HPP

#include "core/stjsonfile.hpp"

#include <QString>

namespace Starstructor { namespace Core {

class Parseable
{
public:
    Parseable() = delete;
    Parseable(const Parseable& other) = delete;
    Parseable& operator=(const Parseable& other) = delete;

    virtual ~Parseable() = 0;

    JsonFile* const getJsonFile();

protected:
    Parseable(const QString& path);
    Parseable(Parseable&& other) = default;

    JsonFile m_json;
};

}

}

#endif // STPARSEABLE_HPP