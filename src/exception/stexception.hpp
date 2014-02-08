/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#ifndef STEXCEPTION_HPP
#define STEXCEPTION_HPP

#include <string>
#include <ostream>

namespace Starstructor { namespace Exception {

class Exception
{
public:
    Exception(const std::string message) throw()
        : m_message("General exception: " + message) 
    {}

    virtual ~Exception()
    {}

    std::string Exception::message() const throw()
    { 
        return m_message; 
    }

private:
    std::string m_message;
};

class FileNotFoundException : public Exception
{
public:
    FileNotFoundException(const std::string message) throw()
        : Exception("File not found exception: " + message)
    {}

    virtual ~FileNotFoundException()
    {}
};

class JsonInvalidFormat : public Exception
{
public:
    JsonInvalidFormat(const std::string message) throw()
        : Exception("Json invalid format exception: " + message)
    {}

    virtual ~JsonInvalidFormat()
    {}
};

}

}

#endif // STEXCEPTION_HPP