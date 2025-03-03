
#include <bits/stdc++.h>
using namespace std;

int minMoves(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int median = nums[nums.size() / 2];
    int moves = 0;
    for (int num : nums) {
        moves += abs(num - median);
    }
    return moves;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << minMoves(nums) << "\n";
    return 0;
}
