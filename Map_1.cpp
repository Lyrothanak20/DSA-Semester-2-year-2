//
// Created by Lyrothanak on 8/08/2025.
//
#include <iostream>
#include <map>
using namespace std;
int main() {
    //Task 1: add element
    map<string, double> studentGrades;
    studentGrades["Dara"] = 85.5;
    studentGrades["Sokha"] = 92.0;
    studentGrades["Bopha"] = 78.5;
//    studentGrades["Thida"] = 90.9;
    //Task 2: Update element
    studentGrades["Dara"] = 88.5;

    // Task 3: Print all students and their grades
    for (auto i : studentGrades) {
        cout << i.first << " --> " << i.second << endl;
    }
    // Task 4: Check if student "Thida" exists
    auto find = studentGrades.find("Thida");
    auto finding = (find != studentGrades.end()) ? "Found" : "Not found";
    cout << finding << endl;
    return 0;
}