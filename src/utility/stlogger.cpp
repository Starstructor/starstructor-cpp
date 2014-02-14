/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#include "utility/stlogger.hpp"

#include <QTextStream>
#include <QTime>

using std::unique_lock;
using std::mutex;

namespace Starstructor { namespace Utility {

Logger::Logger(const QString& path)
    : m_logFile{ path }, m_stream{}
{
    if (!m_logFile.open(QIODevice::WriteOnly | QIODevice::Text))
        throw FileNotFoundException{ "Unable to open log file at " + path };

    m_stream.setDevice(&m_logFile);
}

Logger::~Logger()
{
    m_logFile.close();
}

Logger& Logger::operator<<(const char* input)
{
    unique_lock<mutex> lock{ m_writeMutex };
    m_stream << input;
    m_stream.flush();
    return *this;
}

Logger& Logger::operator<<(std::string input)
{
    unique_lock<mutex> lock{ m_writeMutex };
    m_stream << input.c_str();
    m_stream.flush();
    return *this;
}

Logger& Logger::operator<<(QString input)
{
    unique_lock<mutex> lock{ m_writeMutex };
    m_stream << input; 
    m_stream.flush();
    return *this;
}

Logger& Logger::operator<<(QVariant input)
{
    unique_lock<mutex> lock{ m_writeMutex };
    m_stream << input.toString();
    m_stream.flush();
    return *this;
}

Logger& Logger::operator<<(Exception input)
{
    unique_lock<mutex> lock{ m_writeMutex };
    m_stream << input.what();
    m_stream.flush();
    return *this;
}

Logger& Logger::operator<<(std::exception input)
{
    unique_lock<mutex> lock{ m_writeMutex };
    m_stream << input.what();
    m_stream.flush();
    return *this;
}

Logger& Logger::operator<<(QTextStreamFunction input)
{
    unique_lock<mutex> lock{ m_writeMutex };
    m_stream << input;
    m_stream.flush();
    return *this;
}

void Logger::writeLine(const char* input)
{
    unique_lock<mutex> lock{ m_writeMutex };
    m_stream << getTime() << input << endl;
}

void Logger::writeLine(std::string input)
{
    unique_lock<mutex> lock{ m_writeMutex };
    m_stream << getTime() << input.c_str() << endl;
}

void Logger::writeLine(QString input)
{
    unique_lock<mutex> lock{ m_writeMutex };
    m_stream << getTime() << input << endl;
}

void Logger::writeLine(QVariant input)
{
    unique_lock<mutex> lock{ m_writeMutex };
    m_stream << getTime() << input.toString() << endl;
}

void Logger::writeLine(Exception input)
{
    unique_lock<mutex> lock{ m_writeMutex };
    m_stream << getTime() << input.what() << endl;
}

void Logger::writeLine(std::exception input)
{
    unique_lock<mutex> lock{ m_writeMutex };
    m_stream << getTime() << input.what() << endl;
}

QString Logger::getTime()
{
    const QString format{ "hh:mm:ss zzz" };
    return "[" + QTime::currentTime().toString(format) + "] ";
}

}

}