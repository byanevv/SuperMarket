#include "Warning.h"

Warning::Warning()
    : sender(""), severity(Severity::LOW) {}

Warning::Warning(const MyString& sender ,Severity severity)
    : sender(sender), severity(severity) {}

Warning::Warning(const MyString& sender, int points)
    : sender(sender) {

    if (points == static_cast<int>(Severity::HIGH)) {
        severity = Severity::HIGH;
    }
    else if (points == static_cast<int>(Severity::MEDIUM)) {
        severity = Severity::MEDIUM;
    }
    else {
        severity = Severity::LOW;
    }
}

MyString Warning::getSender() const { return sender; }
MyString Warning::getSeverity() const { 
    
    if (severity == Severity::LOW) {
        return "LOW";
    }
    else if (severity == Severity::MEDIUM) {
        return "MEDIUM";
    }
    else { return "HIGH"; }

}

int Warning::getPoints() const {

    if (severity == Severity::LOW) {
        return 100;
    }
    else if (severity == Severity::MEDIUM) {
        return 200;
    }
    else { return 300; }
}