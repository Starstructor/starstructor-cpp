/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#ifndef STLOGGER_HPP
#define STLOGGER_HPP

#include "stexception.hpp"

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QVariant>

#include <string>
#include <mutex>

namespace Starstructor { namespace Utility {

class Logger final
{
public:
    Logger(const QString& path);
    ~Logger();

    Logger& operator<<(const char* input);
    Logger& operator<<(const std::string& input);
    Logger& operator<<(const QString& input);
    Logger& operator<<(const QVariant& input);
    Logger& operator<<(const Exception& input);
    Logger& operator<<(const std::exception& input);
    Logger& operator<<(const QTextStreamFunction& f);

    void write(const char* input);
    void write(const std::string& input);
    void write(const QString& input);
    void write(const QVariant& input);
    void write(const Exception& input);
    void write(const std::exception& input);

    void writeLine(const char* input);
    void writeLine(const std::string& input);
    void writeLine(const QString& input);
    void writeLine(const QVariant& input);
    void writeLine(const Exception& input);
    void writeLine(const std::exception& input);

    Logger() = delete;
    Logger(const Logger& other) = delete;
    Logger(Logger&& other) = delete;
    Logger& operator=(const Logger& other) = delete;
    Logger& operator=(Logger&& other) = delete;

private:
    QString getTime();

    QTextStream m_stream;
    QFile m_logFile;
    std::recursive_mutex m_writeMutex;
};

}

}

#endif // STLOGGER_HPP