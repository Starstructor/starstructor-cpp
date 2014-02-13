/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#ifndef STMATERIAL_HPP
#define STMATERIAL_HPP

#include "core/object/stasset.hpp"

namespace Starstructor { namespace Core {

class Material : public Asset
{
public:
    Material() = delete;
    Material(const QString& path);

private:
};

}

}

#endif // STMATERIAL_HPP