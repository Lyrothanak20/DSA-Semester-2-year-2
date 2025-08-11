#include <iostream>
using namespace std;
#define size 200
int primeNumber = 107;
//int primeNumber = 7;
string doubleHashingSize[size];
int HashFunction(string word);
int DoubleHashFunction(string word);
bool SearchInHashTable(string word);
int Collision(int indexOfHashTable);
void Inserting(string word);
void Print();
void Display();
int main() {
    Display();
    return 0;
}

int HashFunction(string word) {
    int hugeNumber = 0;
    for (char i : word) {
        hugeNumber += int(i);
    }

    return hugeNumber % size;
}

int DoubleHashFunction(string word) {
    int hugeNumber = 0;
    for (char i : word) {
        hugeNumber += int(i);
    }

    return primeNumber - (hugeNumber % primeNumber);
}

bool SearchInHashTable(string word){
    int index = HashFunction(word);
    int stepSize = DoubleHashFunction(word);
    int secondIndex = index;
    while (doubleHashingSize[index] != ""){
        if (doubleHashingSize[index] == word)
            return true;
        index = (index + stepSize) % size;
        if (index == secondIndex)
            break;
    }
    return false;
}

int Collision(int indexOfHashTable){
    int index = indexOfHashTable;
    while (doubleHashingSize[index] != "") {
        index = (index + 1) % size;
        if (index == indexOfHashTable)
            return -1;
    }
    return index;
}

void Inserting(string word) {
    int index = HashFunction(word);
    int stepSize = DoubleHashFunction(word);
    int secondIndex = index;
    if (doubleHashingSize[index] == "") {
        doubleHashingSize[index] = word;
        return;
    }
    while (doubleHashingSize[index] != "") {
        index = (index + stepSize) % size;
        if (index == secondIndex) {
            cout << "Hash Table is full.";
            return;
        }
    }
    doubleHashingSize[index] = word;
}



void Print(){
    cout << "Hash Table: " << endl;
    for (int i = 0; i < size; i++) {
        if (doubleHashingSize[i] != "") {
            cout << "index " << i << " -> " << doubleHashingSize[i] << endl;
        }
    }
    cout << endl;
}

void Display() {
    Inserting("ck");
    Inserting("kc");
    Inserting("we");
    Inserting("ew");
    Inserting("ta");
    Inserting("kk");
    Inserting("ll");
    Inserting("ii");
    Inserting("tr");
    Inserting("df");
    Inserting("sh");
    Inserting("at");
    Print();
    cout << "step size of (kc) --> " << DoubleHashFunction("kc") << endl;
    cout << "step size of (at) --> " << DoubleHashFunction("at") << endl;

}

// >> Test code
//===========================================================================================
//void Inserting(string word) {
//    int index = HashFunction(word);
//    int newIndex = Collision(index);
//    int stepSize = DoubleHashFunction(word);
//    if (doubleHashingSize[index] == "") {
//        doubleHashingSize[index] = word;
//
//    }
//    if (newIndex == -1){
//        while (word != ""){
//            if (word != ""){
//                doubleHashingSize[index += stepSize];
//                return;
//            }
//        }
//    }
//    else {
//        cout << "Double Hashing is full.";
//        return;
//    }
//}
//===========================================================================================
//void Inserting(string word) {
//    int index = HashFunction(word);
//    int newIndex = Collision(index);
//    int stepSize = DoubleHashFunction(word);
//    if (doubleHashingSize[index] == "") {
//        doubleHashingSize[index] = word;
//        return;
//    }
//    else if (newIndex == -1){
//        index += stepSize;
//        if (index > size){
//            index = index % size;
//        }
//        if (doubleHashingSize[index] == ""){
//            doubleHashingSize[index] = word;
//            return;
//        }
//    }
////    else {
////        cout << "Double Hashing is full.";
////    }
//}
//===========================================================================================
//void Inserting(string word) {
//    int index = HashFunction(word);
//    int stepSize = DoubleHashFunction(word);
//    int secondIndex = index;
//    if (doubleHashingSize[index] == "") {
//        doubleHashingSize[index] = word;
//        return;
//    }
//    while (doubleHashingSize[index] != "") {
//        index = (index + stepSize) % size;
//        if (index == secondIndex) {
//            cout << "Hash Table is full.";
//            return;
//        }
//    }
//    doubleHashingSize[index] = word;
//}