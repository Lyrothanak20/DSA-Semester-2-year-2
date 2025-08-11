#include<iostream> //Recursion
using namespace std;
int recursionSearch(int array[], int target, int lower, int upper);
int main(){
    int listArray[] = {14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    // listArray[15] = {14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int keyTarget;
    int lowerArray = 0;
    int upperArray = sizeof(listArray) / sizeof(listArray[0]);
    int result;
    cout << "Element :";
    for (int i : listArray) {
        cout << i << " ";
    }
    cout << endl; 
    cout << "Enter the value search : ";
    cin >> keyTarget;
    result = recursionSearch(listArray, keyTarget, lowerArray, upperArray);
    cout << "Value : " << keyTarget << " index : " << result;  
    return 0;
}

int recursionSearch(int array[], int target, int lower, int upper){
    int middle;
    middle = (lower + upper) / 2;

    if (array[middle] == target) 
        return middle;
    else if (lower > upper) 
        return -1;
    else {
        if (array[middle] > target)
            return recursionSearch(array, target, middle + 1, upper);
        else 
            return recursionSearch(array, target, lower, middle - 1);
    }

}