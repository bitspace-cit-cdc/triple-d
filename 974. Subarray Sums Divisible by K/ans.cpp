#include <bits/stdc++.h>
using namespace std;

vector<int> subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    vector<int> pre(n, 0);
    pre[0] = nums[0];
    for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + nums[i];
    unordered_map<int, int> mp;
    mp[0] = 1;
    for (auto i : pre) {
        c += mp[(k + i % k) % k];
        mp[(k + i % k) % k]++;
        ans.push_back(c);
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
	
    cin >> k;

	vector<int> query(n);
    for (int i = 0; i < n; i++) {
        cin >> query[i];
    }

	vector<int> ans = subarraysDivByK(nums, k);
    for(auto i:query){
		cout << ans[i] << " ";
	}
	cout<<endl;

    return 0;
}