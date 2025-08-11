//
// Created by Lyrothanak on 8/08/2025.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    // Task 1: Add these test scores for each student
    unordered_map<string, vector<int>> studentScores;
    studentScores["Dara"] = {85, 90, 88};
    studentScores["Sokha"] = {92, 95, 89};

    // Task 2: Calculate and print average score for each student
    for (auto i : studentScores) {
        int total = 0; // create variable to store result
        cout << "Name : " << i.first << " ---> Scores : ";
        for (int score : i.second) {
            total += score;
        }
        cout << total << endl;
    }
    // Task 3 add new score to Dara
    studentScores["Dara"].push_back(93);
    // Task 4 print score again
    for (auto i : studentScores) {
        int total = 0; // create variable to store result
        cout << "Name : " << i.first << " ---> Scores : ";
        for (int score : i.second) {
            total += score;
        }
        cout << total << endl;
    }
    return 0;
}