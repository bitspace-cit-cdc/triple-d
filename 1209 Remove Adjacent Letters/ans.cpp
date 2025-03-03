
#include <bits/stdc++.h>
using namespace std;

string removeLetters(string s, int k, int t) {
    vector<char> stack;
    vector<int> diffs;
    vector<int> prefix_diffs(1, 0);
    for (char c : s) {
        if (stack.empty()) {
            stack.push_back(c);
        } else {
            int diff = abs(c - stack.back());
            stack.push_back(c);
            diffs.push_back(diff);
            prefix_diffs.push_back(prefix_diffs.back() + diff);
        }
        while (stack.size() >= k) {
            int block_sum = prefix_diffs[diffs.size()] - prefix_diffs[diffs.size() - (k - 1)];
            if (block_sum > t) {
                for (int i = 0; i < k; i++) {
                    stack.pop_back();
                }
                for (int i = 0; i < k - 1; i++) {
                    diffs.pop_back();
                    prefix_diffs.pop_back();
                }
            } else {
                break;
            }
        }
    }
    return string(stack.begin(), stack.end());
}

int main() {
    string s;
    int k, t;
    cin >> s >> k >> t;
    cout << removeLetters(s, k, t) << "\n";
    return 0;
}
