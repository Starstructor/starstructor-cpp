/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#ifndef STOBJECT_HPP
#define STOBJECT_HPP

#include "core/object/stasset.hpp"

namespace Starstructor { namespace Core {

class Object : public Asset
{
public:
    Object() = delete;
    Object(const QString& path);

private:
};

}

}

#endif // STOBJECT_HPP