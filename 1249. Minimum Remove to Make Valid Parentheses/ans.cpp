#include <bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string s) {
    stack<pair<char, int>> stack;
    unordered_set<int> to_remove;
    unordered_map<char, char> matching = {{')', '('}, {'}', '{'}, {']', '['}};

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (matching.find(ch) == matching.end()) {
            stack.push({ch, i});
        } else {
            if (!stack.empty() && stack.top().first == matching[ch]) {
                stack.pop();
            } else {
                to_remove.insert(i);
            }
        }
    }

    while (!stack.empty()) {
        to_remove.insert(stack.top().second);
        stack.pop();
    }

    string result = "";
    for (int i = 0; i < s.size(); i++) {
        if (to_remove.find(i) == to_remove.end()) {
            result += s[i];
        }
    }

    return result;
}

int main() {
    string s;
    cin >> s;
    cout << minRemoveToMakeValid(s) << endl;
    return 0;
}