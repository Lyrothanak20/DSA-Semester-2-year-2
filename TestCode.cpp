#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    unordered_map<string, int> wordFrequency;
    string text = "the quick brown fox jumps over the lazy dog the fox";
    string word = "";

    for (int i = 0; i < text.length(); i++) {
        if (text[i] != ' ') {
            word = word + text[i];
        } else {
            if (!word.empty()) {  // Check if word is not empty
                wordFrequency[word]++;
                word = "";
            }
        }
    }

    // Handle the last word (if line doesn't end with space)
    if (!word.empty()) {
        wordFrequency[word]++;
    }

    // Print results
    cout << "Word frequencies:" << endl;
    for ( auto i : wordFrequency) {
        cout << i.first << ": " << i.second << endl;
    }

    return 0;
}