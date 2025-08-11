//
// Created by Lyrothanak on 8/08/2025.
//
#include <iostream>
#include <map>
//#include <unordered_map>
using namespace std;
map<string, string> contacts {
        {"Dara", "012345678"},
        {"Bopha", "023456789"},
        {"Sokha", "034567890"}
};

void addContact();
void searchContact();
void deleteContact();
void displayAllContact();

int main() {
    int option;
    while (option != 5) {
        cout << "1. Add contact" << endl;
        cout << "2. Search contact" << endl;
        cout << "3. Delete contact" << endl;
        cout << "4. Show all contact" << endl;
        cout << "5. Exit." << endl;
        cout << "------>";
        cin >> option;
        switch(option) {
            case 1: addContact(); break;
            case 2: searchContact(); break;
            case 3: deleteContact(); break;
            case 4: displayAllContact(); break;
            case 5: cout << "Exits......." << endl; break;
            default: cout << "Please try again.........";
        }
    }
    return 0;
}

void addContact() {
    string name;
    string phoneNumber;
    cout << "Enter name of contact : ";
    cin >> name;
    cout << "Enter phone number : ";
    cin >> phoneNumber;
    contacts[name] = phoneNumber;
}

void displayAllContact() {
    for (auto i : contacts) {
        cout << "Name : " << i.first << "-->" << "Phone number : " << i.second << endl;
    }
}

void searchContact() {
    string name;
    cout << "Enter name to search : ";
    cin >> name;
    auto finding = contacts.find(name);
    if (finding != contacts.end())
        cout << "Name : " << finding -> first << "-->" << "Phone number : " << finding -> second << endl;
    else
        cout << "Cannot found...." << endl;
}

void deleteContact() {
    string name;
    cout << "Enter name to delete : ";
    cin >> name;
    contacts.erase(name);
    cout << "Deleted...." << endl;
}