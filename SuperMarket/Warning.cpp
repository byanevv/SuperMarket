#include "Warning.h"

Warning::Warning()
    : sender(""), description(""), severity(Severity::LOW) {}

Warning::Warning(const MyString& sender, const MyString& description, Severity severity)
    : sender(sender), description(description), severity(severity) {}

MyString Warning::getSender() const { return sender; }
MyString Warning::getDescription() const { return description; }
Severity Warning::getSeverity() const { return severity; }