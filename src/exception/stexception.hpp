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
    Exception(const std::string& message, const std::string& exType = "General exception") noexcept
        : m_message{ message }, m_exType{ exType }
    {}

    virtual ~Exception()
    {}

    std::string what() const noexcept
    {
        return m_exType + ": " + m_message;
    }

    std::string message() const noexcept
    {
        return m_message;
    }

private:
    std::string m_message;
    std::string m_exType;
};

class FileNotFoundException : public Exception
{
public:
    FileNotFoundException(const std::string& message) noexcept
        : Exception{ message, "File not found exception" }
    {}

    virtual ~FileNotFoundException()
    {}
};

class JsonInvalidFormat : public Exception
{
public:
    JsonInvalidFormat(const std::string& message) noexcept
        : Exception{ message, "JSON invalid format exception" }
    {}

    virtual ~JsonInvalidFormat()
    {}
};

}

}

#endif // STEXCEPTION_HPP
