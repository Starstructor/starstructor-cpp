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
    Logger& operator<<(std::string input);
    Logger& operator<<(QString input);
    Logger& operator<<(QVariant input);
    Logger& operator<<(Exception input);
    Logger& operator<<(std::exception input);
    Logger& operator<<(QTextStreamFunction f);

    void writeLine(const char* input);
    void writeLine(std::string input);
    void writeLine(QString input);
    void writeLine(QVariant input);
    void writeLine(Exception input);
    void writeLine(std::exception input);

    Logger() = delete;
    Logger(const Logger& other) = delete;
    Logger(Logger&& other) = delete;
    Logger& operator=(const Logger& other) = delete;
    Logger& operator=(Logger&& other) = delete;

private:
    QString getTime();

    QFile m_logFile;
    QTextStream m_stream;
    std::mutex m_writeMutex;
};

}

}

#endif // STLOGGER_HPP