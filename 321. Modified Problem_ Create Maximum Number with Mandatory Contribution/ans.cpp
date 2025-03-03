#include <bits/stdc++.h>
using namespace std;
vector<int> maxSubsequence(vector<int>& nums, int k) {
    int drop = nums.size() - k;
    vector<int> stack;
    for (int num : nums) {
        while (!stack.empty() && drop && stack.back() < num) { stack.pop_back(); drop--; }
        stack.push_back(num);
    }
    stack.resize(k);
    return stack;
}
vector<int> merge(vector<int>& seq1, vector<int>& seq2) {
    vector<int> res;
    int i = 0, j = 0;
    while(i < seq1.size() || j < seq2.size()){
        if(lexicographical_compare(seq1.begin()+i, seq1.end(), seq2.begin()+j, seq2.end()))
            res.push_back(seq2[j++]);
        else
            res.push_back(seq1[i++]);
    }
    return res;
}
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size(), n = nums2.size();
    vector<int> best;
    for (int i = max(1, k - n); i <= min(k - 1, m); i++) {
        vector<int> sub1 = maxSubsequence(nums1, i);
        vector<int> sub2 = maxSubsequence(nums2, k - i);
        vector<int> candidate = merge(sub1, sub2);
        if(candidate > best) best = candidate;
    }
    return best;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int m, n, k;
        cin >> m;
        vector<int> nums1(m);
        for(int i = 0; i < m; i++) cin >> nums1[i];
        cin >> n;
        vector<int> nums2(n);
        for(int i = 0; i < n; i++) cin >> nums2[i];
        cin >> k;
        vector<int> ans = maxNumber(nums1, nums2, k);
        if(ans.empty()) cout << -1 << "\n";
        else { for(auto num : ans) cout << num << " "; cout << "\n"; }
    }
    return 0;
}