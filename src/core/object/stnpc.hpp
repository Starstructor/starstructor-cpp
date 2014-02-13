/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#ifndef STNPC_HPP
#define STNPC_HPP

#include "core/object/stasset.hpp"

namespace Starstructor { namespace Core {

class NPC : public Asset
{
public:
    NPC() = delete;
    NPC(const QString& path);

private:
};

}

}

#endif // STNPC_HPP