#include <bits/stdc++.h>
using namespace std;

int minCost(string colors, vector<int>& neededTime) {
    int n = neededTime.size(), f = 1, ans = 0;
    vector<int> v(1, neededTime[0]);
    for (int i = 1; i < n; i++) {
        if (colors[i] == colors[i - 1]) {
            v.push_back(neededTime[i]);
            f++;
        } else {
            if (f > 2) {
                int max = INT_MIN, c = 0, second_max = INT_MIN;

                for (int i = 0; i < v.size(); i++) {
                    if (v[i] > max) {
                        second_max = max;
                        max = v[i];
                    } else if (v[i] > second_max) {
                        second_max = v[i];
                    }
                    c += v[i];
                }
                ans += c - max - second_max;
                v.clear();
                v.push_back(0);
            }
            f = 1;
            v[0] = neededTime[i];
        }
    }
    if (f > 2) {
        int max = INT_MIN, c = 0, second_max = INT_MIN;

        for (int i = 0; i < v.size(); i++) {
            if (v[i] > max) {
                second_max = max;
                max = v[i];
            } else if (v[i] > second_max) {
                second_max = v[i];
            }
            c += v[i];
        }
        ans += c - max - second_max;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    
    string colors;
    cin >> colors;

    vector<int> neededTime(n);
    for (int i = 0; i < n; i++) {
        cin >> neededTime[i];
    }

    int result = minCost(colors, neededTime);
    cout << result << endl;

    return 0;
}