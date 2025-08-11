#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    unordered_map<string, int> word_frequency;
    string current_line = "hello world hello programming world";  // Example input
    string word = "";

    for (int i = 0; i < current_line.length(); i++) {
        if (current_line[i] != ' ') {
            word = word + current_line[i];
        } else {
            if (!word.empty()) {  // Check if word is not empty
                word_frequency[word]++;
                word = "";
            }
        }
    }

    // Handle the last word (if line doesn't end with space)
    if (!word.empty()) {
        word_frequency[word]++;
    }

    // Find word with highest frequency
    string most_frequent_word = "";
    int max_frequency = 0;

    for (const auto& pair : word_frequency) {
        if (pair.second > max_frequency) {
            max_frequency = pair.second;
            most_frequent_word = pair.first;
        }
    }

    // Print results
    cout << "Word frequencies:" << endl;
    for (const auto& pair : word_frequency) {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "\nMost frequent word: \"" << most_frequent_word
         << "\" with frequency: " << max_frequency << endl;

    return 0;
}