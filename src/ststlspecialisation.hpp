/*
Starstructor, the Starbound Toolset 
Copyright (C) 2013-2014 Chris Stamford
Licensed under terms of The MIT License (MIT)

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com
*/

#ifndef STSTLSPECIALIZATION_HPP
#define STSTLSPECIALIZATION_HPP

#include <QHash>
#include <QString>

namespace std
{
    template <>
    struct hash<QString>
    {
        size_t operator()(const QString& val) const
        {
            return qHash(val);
        }
    };
}


#endif // STSTLSPECIALIZATION_HPP