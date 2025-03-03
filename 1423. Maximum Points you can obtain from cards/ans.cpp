#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k, int m) {
    int n = cardPoints.size(), max_points = 0;

    for (int left = 0; left <= min(m, k); ++left) {
        int right = k - left;
        if (right > min(m, k)) continue;

        int left_sum = accumulate(cardPoints.begin(), cardPoints.begin() + left, 0);
        int right_sum = (right > 0) ? accumulate(cardPoints.end() - right, cardPoints.end(), 0) : 0;
        
        max_points = max(max_points, left_sum + right_sum);
    }
    
    return max_points;
}

int main() {
    int n, k, m;
    cin >> n;
    vector<int> cardPoints(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> cardPoints[i];
    }

    cin >> k >> m;
    cout << maxScore(cardPoints, k, m) << endl;
    
    return 0;
}