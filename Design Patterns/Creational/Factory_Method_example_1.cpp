#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Product Interface 
class Logger {
public:
    virtual void log(const string& message) const = 0;
    virtual ~Logger() = default;
};

// Concrete product: Logger for Windows, writes to a file
class FileLogger : public Logger {
public:
    void log(const string& message) const override {
        cout << "[FileLogger] Writing to a file: " << message << endl;
    }
};

// Concrete product: Logger for Linux, writes to system log
class SysLogger : public Logger {
public:
    void log(const string& message) const override {
        cout << "[SysLogger] Writing to syslog: " << message << endl;
    }
};

// Concrete product: Logger for macOS, outputs to console
class ConsoleLogger : public Logger {
public:
    void log(const string& message) const override {
        cout << "[ConsoleLogger] Output to console: " << message << endl;
    }
};

// Factory interface — defines a method for creating loggers
class LoggerFactory {
public:
    virtual unique_ptr<Logger> createLogger() const = 0;
    virtual ~LoggerFactory() = default;
};

// Concrete factory: for Windows
class WindowsLoggerFactory : public LoggerFactory {
public:
    unique_ptr<Logger> createLogger() const override {
        return make_unique<FileLogger>();
    }
};

// Concrete factory: for Linux
class LinuxLoggerFactory : public LoggerFactory {
public:
    unique_ptr<Logger> createLogger() const override {
        return make_unique<SysLogger>();
    }
};

// Concrete factory: for macOS
class MacOSLoggerFactory : public LoggerFactory {
public:
    unique_ptr<Logger> createLogger() const override {
        return make_unique<ConsoleLogger>();
    }
};

// Function that uses the factory method for logging
void clientCode(const LoggerFactory& factory, const string& message) {
    auto logger = factory.createLogger();
    logger->log(message);
}

int main() 
{
    cout << "Select platform (1 - Windows, 2 - Linux, 3 - macOS): ";
    int platform;
    cin >> platform;

    unique_ptr<LoggerFactory> factory;

    if (platform == 1) {
        factory = make_unique<WindowsLoggerFactory>();
    } else if (platform == 2) {
        factory = make_unique<LinuxLoggerFactory>();
    } else if (platform == 3) {
        factory = make_unique<MacOSLoggerFactory>();
    } else {
        cout << "Invalid platform!" << endl;
        return 1;
    }

    clientCode(*factory, "Application started");
    clientCode(*factory, "This is a log message");
    clientCode(*factory, "Application finished");

    return 0;
}
