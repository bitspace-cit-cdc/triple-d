#include <bits/stdc++.h>
using namespace std;
int ans;
void dfs(vector<tuple<int,int,int>> &cand, int idx, int mask, int vowelCount, int length, int k) {
    if(vowelCount >= k) ans = max(ans, length);
    for(int i = idx; i < cand.size(); i++){
        int cMask, cVowel, cLen;
        tie(cMask, cVowel, cLen) = cand[i];
        if(mask & cMask) continue;
        dfs(cand, i+1, mask | cMask, vowelCount + cVowel, length + cLen, k);
    }
}
int maxLength(vector<string>& arr, int k) {
    vector<tuple<int,int,int>> cand;
    for(auto &s : arr){
        int mask = 0, vowels = 0;
        bool valid = true;
        for(char c : s){
            int bit = c - 'a';
            if(mask & (1 << bit)) { valid = false; break; }
            mask |= (1 << bit);
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') vowels++;
        }
        if(valid) cand.push_back({mask, vowels, (int)s.size()});
    }
    ans = 0;
    dfs(cand, 0, 0, 0, 0, k);
    return ans;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n;
        vector<string> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        cin >> k;
        cout << maxLength(arr, k) << "\n";
    }
    return 0;
}