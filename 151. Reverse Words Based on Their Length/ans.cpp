#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    stringstream ss(s);
    vector<string> words;
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    string result = "";
    for (int i = words.size() - 1; i >= 0; --i) {
        string currentWord = words[i];
        if (currentWord.length() % 2 != 0) {
            reverse(currentWord.begin(), currentWord.end());
        }
        result += currentWord + " ";
    }

    if (!result.empty()) {
        result.pop_back();
    }
    return result;
}

int main() {
    string s;
    getline(cin, s);
    cout << reverseWords(s) << endl;
    return 0;
}