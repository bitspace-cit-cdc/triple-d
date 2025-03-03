#include <bits/stdc++.h>
using namespace std;

int minimumSize(vector<int>& nums, int k) {
    const int n = nums.size();
    int l = 1, r = *max_element(nums.begin(), nums.end()), m;
    while (l < r) {
        m = l + (r - l) / 2;
        long long cnt = 0;
        for (int j = 0; j < n && cnt <= k; j++)
            cnt += (nums[j] - 1) / m;
        if (cnt <= k)
            r = m;
        else
            l = m + 1;
    }
    return r;
}

void removeMaxElement(vector<int>& nums) {
    auto it = max_element(nums.begin(), nums.end());
    if (it != nums.end()) {
        nums.erase(it);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    removeMaxElement(nums);
    int result = minimumSize(nums, k);
    cout << result << endl;

    return 0;
}