
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    long long k, s;
    cin >> k >> s;
    unordered_map<long long,int> freq;
    for (auto x : nums){
        freq[x]++;
    }
    long long ans = 0;
    if(k == 0){
        for(auto &p : freq){
            if(p.second >= 2 && 2*p.first <= s){
                ans++;
            }
        }
    } else {
        for(auto &p : freq){
            long long x = p.first;
            long long y = x + k;
            if(freq.count(y) && (x + y) <= s){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
