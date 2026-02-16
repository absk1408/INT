#include <iostream>
#include "Student.h"
using namespace std;

Student::Student(string n, int a) {
    name = n;
    age = a;
}

void Student::display() {
    cout << "Name: " << name << ", Age: " << age << endl;
}
