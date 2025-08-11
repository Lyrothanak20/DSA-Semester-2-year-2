#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    unordered_map<string, int> wordFrequency;
    string text = "the quick brown fox jumps over the lazy dog the fox";
    string word = "";
    string highestWord  = "";
    int countHighestWord = 0;

    for (int i = 0; i < text.length(); i++) {
        if (text[i] != ' ') {
            word = word + text[i];
        } else {
            if (!word.empty()) {
                wordFrequency[word]++;
                word = "";
            }
        }
    }

    // Check word frequency
    if (!word.empty()) {
        wordFrequency[word]++;
    }

    for (auto i : wordFrequency) {
        if (i.second > countHighestWord) {
            countHighestWord = i.second;
            highestWord = i.first;
        }
    }

    cout << "Word frequencies:" << endl;
    for ( auto i : wordFrequency) {
        cout << i.first << ": " << i.second << endl;
    }

    cout << "Highest frequency : " << highestWord;
    return 0;
}