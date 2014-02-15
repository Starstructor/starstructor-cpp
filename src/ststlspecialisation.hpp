/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
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