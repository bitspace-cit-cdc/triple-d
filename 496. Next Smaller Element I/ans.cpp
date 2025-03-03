#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mpp;
    stack<int> st;

    for (int i = nums2.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() >= nums2[i]) {
            st.pop();
        }

        if (!st.empty())
            mpp[nums2[i]] = st.top();
        else
            mpp[nums2[i]] = -1;
        st.push(nums2[i]);
    }
    vector<int> ans;
    for (int num : nums1) {
        ans.push_back(mpp[num]);
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> nums1(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums1[i];
    }
    
    cin >> m;
    vector<int> nums2(m);
    for (int i = 0; i < m; ++i) {
        cin >> nums2[i];
    }

    vector<int> result = nextGreaterElement(nums1, nums2);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}