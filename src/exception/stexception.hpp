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

namespace Starstructor { namespace Except {

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

class FileException : public Exception
{
public:
    FileException(const std::string message) throw()
        : Exception("File exception: " + message)
    {}

    virtual ~FileException()
    {}
};

class JsonException : public Exception
{
public:
    JsonException(const std::string message) throw()
        : JsonException("Json exception: " + message)
    {}

    virtual ~JsonException()
    {}
};

std::ostream& operator<<(std::ostream& os, const Exception& ex) throw()
{
    os << ex.message(); return os;
}

}

}

#endif // STEXCEPTION_HPP