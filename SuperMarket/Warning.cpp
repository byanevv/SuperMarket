#include "Warning.h"

Warning::Warning()
    : sender(""), severity(Severity::LOW) {}

Warning::Warning(const MyString& sender ,Severity severity)
    : sender(sender), severity(severity) {}

Warning::Warning(const MyString& sender, int points)
    : sender(sender) {

    if (points >= static_cast<int>(Severity::HIGH)) {
        severity = Severity::HIGH;
    }
    else if (points >= static_cast<int>(Severity::MEDIUM)) {
        severity = Severity::MEDIUM;
    }
    else {
        severity = Severity::LOW;
    }
}

MyString Warning::getSender() const { return sender; }
Severity Warning::getSeverity() const { return severity; }

int Warning::getPoints() const {
    return static_cast<int>(severity);
}