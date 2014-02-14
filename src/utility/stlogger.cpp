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
#include <QDebug>

using std::lock_guard;
using std::mutex;

namespace Starstructor { namespace Utility {

Logger::Logger(const QString& path)
    : m_logFile{ path }, m_stream{}, m_writeMutex{}
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
    lock_guard<mutex> lock{ m_writeMutex };
    m_stream << input;
    m_stream.flush();

#ifdef ST_USE_CONSOLE
    qDebug() << input;
#endif
    return *this;
}

Logger& Logger::operator<<(const std::string& input)
{
    lock_guard<mutex> lock{ m_writeMutex };
    m_stream << input.c_str();
    m_stream.flush();

#ifdef ST_USE_CONSOLE
    qDebug() << input.c_str();
#endif

    return *this;
}

Logger& Logger::operator<<(const QString& input)
{
    lock_guard<mutex> lock{ m_writeMutex };
    m_stream << input; 
    m_stream.flush();

#ifdef ST_USE_CONSOLE
    qDebug() << input;
#endif

    return *this;
}

Logger& Logger::operator<<(const QVariant& input)
{
    lock_guard<mutex> lock{ m_writeMutex };
    m_stream << input.toString();
    m_stream.flush();

#ifdef ST_USE_CONSOLE
    qDebug() << input;
#endif

    return *this;
}

Logger& Logger::operator<<(const Exception& input)
{
    lock_guard<mutex> lock{ m_writeMutex };
    m_stream << input.what();
    m_stream.flush();

#ifdef ST_USE_CONSOLE
    qDebug() << input.what();
#endif

    return *this;
}

Logger& Logger::operator<<(const std::exception& input)
{
    lock_guard<mutex> lock{ m_writeMutex };
    m_stream << input.what();
    m_stream.flush();

#ifdef ST_USE_CONSOLE
    qDebug() << input.what();
#endif

    return *this;
}

Logger& Logger::operator<<(const QTextStreamFunction& input)
{
    lock_guard<mutex> lock{ m_writeMutex };
    m_stream << input;
    m_stream.flush();

#ifdef ST_USE_CONSOLE
    qDebug() << input;
#endif

    return *this;
}

void Logger::writeLine(const char* input)
{
    lock_guard<mutex> lock{ m_writeMutex };
    const QString formattedInput{ getTime() + input };
    m_stream << formattedInput << endl;

#ifdef ST_USE_CONSOLE
    qDebug() << formattedInput;
#endif
}

void Logger::writeLine(const std::string& input)
{
    lock_guard<mutex> lock{ m_writeMutex };
    const QString formattedInput{ getTime() + input.c_str() };
    m_stream << formattedInput << endl;

#ifdef ST_USE_CONSOLE
    qDebug() << formattedInput;
#endif
}

void Logger::writeLine(const QString& input)
{
    lock_guard<mutex> lock{ m_writeMutex };
    const QString formattedInput{ getTime() + input };
    m_stream << formattedInput << endl;

#ifdef ST_USE_CONSOLE
    qDebug() << formattedInput;
#endif
}

void Logger::writeLine(const QVariant& input)
{
    lock_guard<mutex> lock{ m_writeMutex };
    const QString formattedInput{ getTime() + input.toString() };
    m_stream << formattedInput << endl;

#ifdef ST_USE_CONSOLE
    qDebug() << formattedInput;
#endif
}

void Logger::writeLine(const Exception& input)
{
    lock_guard<mutex> lock{ m_writeMutex };
    const QString formattedInput{ getTime() + input.what() };
    m_stream << formattedInput << endl;

#ifdef ST_USE_CONSOLE
    qDebug() << formattedInput;
#endif
}

void Logger::writeLine(const std::exception& input)
{
    lock_guard<mutex> lock{ m_writeMutex };
    const QString formattedInput{ getTime() + input.what() };
    m_stream << formattedInput << endl;

#ifdef ST_USE_CONSOLE
    qDebug() << formattedInput;
#endif
}

QString Logger::getTime()
{
    const QString format{ "hh:mm:ss zzz" };
    return "[" + QTime::currentTime().toString(format) + "] ";
}

}

}