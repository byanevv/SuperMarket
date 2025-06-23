#pragma once

#include "MyString.h"

enum class Severity {
    LOW = 100,
    MEDIUM = 200,
    HIGH = 300
};

class Warning {
private:
    MyString sender;
    Severity severity;

public:
    Warning();
    Warning(const MyString& sender, Severity severity);
    Warning(const MyString& sender, int points);

    MyString getSender() const;
    Severity getSeverity() const;

    int getPoints() const;
};
