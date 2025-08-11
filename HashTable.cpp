#include <iostream>
//#include <string>
#define arraySize 100 // size hash table
using namespace std;
string hashTable[arraySize]; // hash table
void Inserting(string word); // for insert value
int HashFunction(string word); // for create key or index
bool SearchInHashTable(string word); // check hash table have or not
int Collision(int indexOfHashTable);
void Print(); // for print array
void Display(); // display program

int main()
{
    Display();
    return 0;
}

void Inserting(string word) {
    int index = HashFunction(word);
    int newIndex = Collision(index);
    if (hashTable[index] == "") {
        hashTable[index] = word;
    }
    else {

        if(newIndex != -1)
            hashTable[newIndex] = word;
        else // is full hash table
            cout << "Hash table is full." << endl;
    }
}
int HashFunction(string word) {
    int hugeNumber = 0;
    for (char i : word) {
        hugeNumber += int(i);
    }
    return  hugeNumber % arraySize;
}

int Collision(int indexOfHashTable){
    int index = indexOfHashTable;
    while (hashTable[index] != "") {
        index = (index + 1) % arraySize;
        if (index == indexOfHashTable)
            return -1;
    }
    return index;
}

bool SearchInHashTable(string word){
    int index = HashFunction(word);
    int nexIndex = index;
    while (hashTable[index] != ""){
        if (hashTable[index] == word)
            return true;
        index = (index + 1) % arraySize;
        if (index == nexIndex)
            break;
    }
    return false;
}

void Print(){
    for (int i = 0; i < arraySize; i++) {
        if (hashTable[i] != "") {
            cout << "index " << i << " -> " << hashTable[i] << endl;
        }
    }
    cout << endl;
}

void Display() {
    int option;
    string word;
    while (true) {
        cout << "==================================================" << endl;
        cout << "1. Add Hash Table " << endl;
        cout << "2. View Hash Table " << endl;
        cout << "3. Check Hash Table " << endl;
        cout << "4. Exits " << endl;
        cout << "Enter option ->  ";
        cin >> option;
        switch(option){
            case 1:{
                cout << "==================================================" << endl;
                cout << "Enter the value : ";
                cin >> word;
                Inserting(word);
                break;
            }
            case 2:{
               cout << "==================================================" << endl;
               Print();
               break;
            }
            case 3:{
                cout << "==================================================" << endl;
                cout << "Enter value to search : ";
                cin >> word;
                if (SearchInHashTable(word))
                    cout << word <<" found value in Hash Table." << endl;
                else
                    cout << word <<  " Not found value." << endl;
                break;
            }
            case 4: {
                cout << "==================================================" << endl;
                cout << "Shut down Hash table." << endl;
                return;
            }
            default:
                cout << "==================================================" << endl;
                cout << "Not this Option." << endl;
                break;
        }
    }
}
