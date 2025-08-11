#include <iostream>  // Quick sort
using namespace std;
//function:
void printArray(int array[], int length);
void swap(int *a, int *b);
int partition(int array[], int low, int high);
void qiuckSort(int array[], int low, int high);

int main() {
    int array[] = {0, 3, 5, 6, 8, 2, 4, 9, 7}; // create array
    // find the size of array or index array
    int length = sizeof(array) / sizeof(array[0]); 
    //print before sort:
    printArray(array, length);
    // using quick sort to value:
    qiuckSort(array, 0, length);
    printArray(array, length); // print after sort
    return 0;
}

void printArray(int array[], int length){
    // length = sizeof(array) / sizeof(array[0]);
    cout << "Element Array: ";
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b){
    int temp;
    temp = *a; // pass by reference
    *a = *b; 
    *b = temp;
    // swap valueA to valueB
}

int partition(int array[], int low, int high){
    int pivot = array[high]; 
    int pIndex = low;
    
    for (int i = low; i < high; i++) {
        if (array[i] <= pivot) {
            swap(&array[i], &array[pIndex]);
            pIndex += 1; 
            //pIndex = pIndex + 1;
            //Pindex++;
        }
    }
    //Call swap()
    swap(&array[pIndex], &array[high]);
    return pIndex;
}

void qiuckSort(int array[], int low, int high) {
    if (low < high) {
        int pIndex = partition(array, low, high); // call function use
        qiuckSort(array, low, pIndex - 1); //recursive function
        qiuckSort(array, pIndex + 1, high);
    }
    else if (low >= high)
        return;
}