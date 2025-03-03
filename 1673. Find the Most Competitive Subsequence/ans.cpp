#include <bits/stdc++.h>
using namespace std;

vector<int> mostCompetitive(vector<int>& A, int k) {
    vector<int> stack;
    for (int i = 0; i < A.size(); ++i) {
        while (!stack.empty() && stack.back() < A[i] &&
               stack.size() - 1 + A.size() - i >= k)
            stack.pop_back();
        if (stack.size() < k)
            stack.push_back(A[i]);
    }
    return stack;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<int> result = mostCompetitive(A, k);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}