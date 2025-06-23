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
    MyString description;
    Severity severity;

public:
    Warning();
    Warning(const MyString& sender, const MyString& description, Severity severity);

    MyString getSender() const;
    MyString getDescription() const;
    Severity getSeverity() const;
};
