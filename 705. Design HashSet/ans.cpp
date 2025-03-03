#include <bits/stdc++.h>
using namespace std;

class EnhancedHashSet {
private:
    vector<int> freq;

public:
    EnhancedHashSet() : freq(1000001, 0) {}

    void add(int key) {
        freq[key]++;
    }

    void remove(int key) {
        freq[key] = 0;
    }

    bool contains(int key) {
        return freq[key] > 0;
    }

    int getFrequency(int key) {
        return freq[key];
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> commands(n);
    for (int i = 0; i < n; i++) {
        cin >> commands[i];
    }

    vector<int> values;
    for (int i = 1; i < n; i++) {
        if (commands[i] != "EnhancedHashSet") {
            int key;
            cin >> key;
            values.push_back(key);
        }
    }

    EnhancedHashSet hashSet;
    int index = 0;

    for (const string& command : commands) {
        if (command == "add") {
            hashSet.add(values[index]);
            cout << "null\n";
            index++;
        } else if (command == "remove") {
            hashSet.remove(values[index]);
            cout << "null\n";
            index++;
        } else if (command == "contains") {
            cout << (hashSet.contains(values[index]) ? "true" : "false") << "\n";
            index++;
        } else if (command == "getFrequency") {
            cout << hashSet.getFrequency(values[index]) << "\n";
            index++;
        } else {
            cout << "null\n";
        }
    }

    return 0;
}
