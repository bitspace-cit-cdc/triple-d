#include <bits/stdc++.h>
using namespace std;

struct State {
    int pos;
    bool usedSpecial;
    bool lastBackward;
};

int solve(vector<int>& forbidden, int a, int b, int x) {
    unordered_set<int> forb(forbidden.begin(), forbidden.end());
    
    int maxForbidden = 0;
    if (!forbidden.empty()) {
        maxForbidden = *max_element(forbidden.begin(), forbidden.end());
    }
    int upper_bound = max(x, maxForbidden) + a + b + 1000; 

    queue<tuple<int, bool, bool, int>> q;
    q.push({0, false, false, 0});
    
    unordered_set<string> visited;
    visited.insert("0_0_0");
    
    while (!q.empty()) {
        auto [pos, usedSpecial, lastBackward, jumps] = q.front();
        q.pop();
        
        if (pos == x) return jumps;
        
        int nextPos = pos + a;
        if (nextPos <= upper_bound && forb.find(nextPos) == forb.end()) {
            string stateKey = to_string(nextPos) + "_" + to_string(usedSpecial) + "_0"; 
            if (visited.find(stateKey) == visited.end()) {
                visited.insert(stateKey);
                q.push({nextPos, usedSpecial, false, jumps + 1});
            }
        }
        
        if (!usedSpecial) {
            int specialPos = pos + 2 * a;
            if (specialPos <= upper_bound && forb.find(specialPos) == forb.end()) {
                string stateKey = to_string(specialPos) + "_1_0"; 
                if (visited.find(stateKey) == visited.end()) {
                    visited.insert(stateKey);
                    q.push({specialPos, true, false, jumps + 1});
                }
            }
        }
        
        if (!lastBackward) {
            int backPos = pos - b;
            if (backPos >= 0 && forb.find(backPos) == forb.end()) {
                string stateKey = to_string(backPos) + "_" + to_string(usedSpecial) + "_1";
                if (visited.find(stateKey) == visited.end()) {
                    visited.insert(stateKey);
                    q.push({backPos, usedSpecial, true, jumps + 1});
                }
            }
        }
    }
    
    return -1;
}

int main() {
    // Example usage:
    int t;
    cin >> t;
    while(t--){
	    int n; cin >> n;
	    vector<int> arr(n);
	    for(int i = 0; i < n; i++) cin >> arr[i];
	    cin >> a >> b >> x;
	    cout << solve(arr,a,b,x) << endl;
    }
    return 0;
}