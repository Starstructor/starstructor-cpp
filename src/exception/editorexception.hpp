/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#ifndef EDITOR_EXCEPTION_HPP
#define EDITOR_EXCEPTION_HPP

#include <string>
#include <ostream>

namespace Starstructor { namespace Exception {

class EditorException
{
public:
    EditorException(const std::string message) throw()
        : m_message("General exception: " + message) 
    {}

    virtual ~EditorException() 
    {}

    std::string EditorException::message() const throw()
    { 
        return m_message; 
    }

private:
    std::string m_message;
};

class EditorFileException : public EditorException
{
public:
    EditorFileException(const std::string message) throw()
        : EditorException("File exception: " + message) 
    {}

    virtual ~EditorFileException() 
    {}
};

class EditorJsonException : public EditorException
{
public:
    EditorJsonException(const std::string message) throw()
        : EditorJsonException("Json exception: " + message)
    {}

    virtual ~EditorJsonException() 
    {}
};

std::ostream& operator<<(std::ostream& os, const EditorException& ex) throw()
{
    os << ex.message(); return os;
}

}

}

#endif // EDITOR_EXCEPTION_HPP