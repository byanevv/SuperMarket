#include "Worker.h"

int Worker::nextId = 1;

Worker::Worker(const MyString& firstName, const MyString& lastName,
    const MyString& phone, int age, const MyString& password)
    : id(nextId++), firstName(firstName), lastName(lastName),
    phone(phone), age(age), password(password) {}

int Worker::getId() const { return id; }
MyString Worker::getFirstName() const { return firstName; }
MyString Worker::getLastName() const { return lastName; }
MyString Worker::getPhone() const { return phone; }
int Worker::getAge() const { return age; }
MyString Worker::getPassword() const { return password; }