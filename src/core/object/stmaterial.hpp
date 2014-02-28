/*
Starstructor, the Starbound Toolset 
Copyright (C) 2013-2014 Chris Stamford
Licensed under terms of The MIT License (MIT)

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com
*/

#ifndef STMATERIAL_HPP
#define STMATERIAL_HPP

#include "core/object/stasset.hpp"

namespace Starstructor { namespace Core {

struct MaterialInfo; 
struct MaterialRenderingInfo; 
struct PlatformRenderingInfo;

class Material : public Asset
{
public:
    Material() = delete;
    Material(const QString& path);

private:
    QString m_name;
    int m_id;

};

struct MaterialInfo
{

};

struct MaterialRenderingInfo
{

};

struct PlatformRenderingInfo
{

};

}

}

#endif // STMATERIAL_HPP