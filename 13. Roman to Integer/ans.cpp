#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> romanMap = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int result = 0;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && romanMap[s[i]] < romanMap[s[i + 1]]) {
            result -= romanMap[s[i]];
        } else {
            result += romanMap[s[i]];
        }
    }
    
    return result;
}

int main() {
    string s;
    cin >> s;

    for (char c : s) {
        if (romanMap.find(c) == romanMap.end()) {
            cout << "0" << endl;
            return 0;
        }
    }
    
    cout << romanToInt(s) << endl;
    return 0;
}