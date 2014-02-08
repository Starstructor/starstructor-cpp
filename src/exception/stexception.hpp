/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#ifndef ST_EXCEPTION_HPP
#define ST_EXCEPTION_HPP

#include <string>
#include <ostream>

namespace Starstructor { namespace Exception {

class STException
{
public:
    STException(const std::string message) throw()
        : m_message("General exception: " + message) 
    {}

    virtual ~STException()
    {}

    std::string STException::message() const throw()
    { 
        return m_message; 
    }

private:
    std::string m_message;
};

class STFileException : public STException
{
public:
    STFileException(const std::string message) throw()
        : STException("File exception: " + message)
    {}

    virtual ~STFileException()
    {}
};

class STJsonException : public STException
{
public:
    STJsonException(const std::string message) throw()
        : STJsonException("Json exception: " + message)
    {}

    virtual ~STJsonException()
    {}
};

std::ostream& operator<<(std::ostream& os, const STException& ex) throw()
{
    os << ex.message(); return os;
}

}

}

#endif // ST_EXCEPTION_HPP