#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
string sFiltered;
vector<vector<int>> memo;
 
int dp(int i, int j) {
    if(i > j) return 0;
    if(memo[i][j] != -1) return memo[i][j];
    long long ans = 0;
    // Iterate over all lowercase letters
    for(char c = 'a'; c <= 'z'; c++){
        int left = i, right = j;
        while(left <= j && sFiltered[left] != c) left++;
        while(right >= i && sFiltered[right] != c) right--;
        if(left > j) continue; // c not found in sFiltered[i..j]
        if(left == right) {
            ans = (ans + 1) % MOD;
        } else {
            ans = (ans + 2 + dp(left+1, right-1)) % MOD;
        }
    }
    memo[i][j] = ans;
    return ans;
}
 
int countPalindromicSubsequences(string s, string allowed) {
    unordered_set<char> allowSet(allowed.begin(), allowed.end());
    sFiltered = "";
    for(char c : s) {
        if(allowSet.count(c)) sFiltered.push_back(c);
    }
    int n = sFiltered.size();
    memo.assign(n, vector<int>(n, -1));
    return dp(0, n-1);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        string s, allowed;
        cin >> s >> allowed;
        cout << countPalindromicSubsequences(s, allowed) << "\n";
    }
    return 0;
}