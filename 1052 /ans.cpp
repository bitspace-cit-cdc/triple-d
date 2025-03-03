#include <bits/stdc++.h>
using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n = customers.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (grumpy[i] == 0) {
            ans += customers[i];
        }
    }

    int unsatis = 0;
    for (int i = 0; i < minutes; i++) {
        if (grumpy[i] == 1) {
            unsatis += customers[i];
        }
    }

    int max = unsatis;
    for (int i = minutes; i < n; i++) {
        if (grumpy[i - minutes] == 1) {
            unsatis -= customers[i - minutes];
        }
        if (grumpy[i] == 1) {
            unsatis += customers[i];
        }
        max = max(max, unsatis);
    }

    return ans + max;
}

int main() {
    int n, minutes;
    cin >> n;
    vector<int> customers(n), grumpy(n);
    
    for (int i = 0; i < n; i++) {
        cin >> customers[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> grumpy[i];
    }
    
    cin >> minutes;

    cout << maxSatisfied(customers, grumpy, minutes) << endl;

    return 0;
}