#include <bits/stdc++.h>
using namespace std;

int furthestBuilding(vector<int>& A, int bricks, int ladders) {
    priority_queue<int> pq;
    for (int i = 0; i < A.size() - 1; i++) {
        int d = A[i + 1] - A[i];
        if (d > 0)
            pq.push(-d);
        if (pq.size() > ladders) {
            bricks += pq.top();
            pq.pop();
            bricks++;
        }
        bricks--;
        if (bricks < 0)
            return i;
    }
    return A.size() - 1;
}

int main() {
    int n, bricks, ladders;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cin >> bricks >> ladders;

    cout << furthestBuilding(A, bricks, ladders) << endl;

    return 0;
}