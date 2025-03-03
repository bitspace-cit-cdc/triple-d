
#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k, int l) {
    int n = nums.size(), sum = 0;
    unordered_set<int> mods;
    
    for (int i = 0; i < l; ++i) sum += nums[i];
    if (sum % k == 0) return true;
    
    for (int i = l; i < n; ++i) {
        sum += nums[i] - nums[i - l];
        if (sum % k == 0) return true;
    }
    
    return false;
}

int main() {
    int n, k, l;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cin >> k >> l;
    cout << (checkSubarraySum(nums, k, l) ? "true" : "false") << endl;
    return 0;
}
