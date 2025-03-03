#include <bits/stdc++.h>

using namespace std;

int solve(int num) {
    string numStr = to_string(num);
    string reversedStr = numStr;
    reverse(reversedStr.begin(), reversedStr.end());
    
    // Check if the number is already a palindrome
    if (numStr == reversedStr) {
        return 0;
    }
    
    vector<string> candidates;
    int l = numStr.length();
    
    if (l > 1) {
        candidates.push_back(string(l - 1, '9')); 
    }
    candidates.push_back("1" + string(l - 1, '0') + "1"); 
    
    int k = (l + 1) / 2;
    string prefix = numStr.substr(0, k);
    
    for (int delta : {-1, 0, 1}) {
        int newPrefixNum = stoi(prefix) + delta;
        string newPrefix = to_string(newPrefixNum);
        
        string candidate;
        if (l % 2 == 0) {
            candidate = newPrefix + string(newPrefix.rbegin(), newPrefix.rend());
        } else {
            candidate = newPrefix + string(newPrefix.rbegin() + 1, newPrefix.rend());
        }
        candidates.push_back(candidate);
    }
    
    int originalNum = num;
    int minSteps = INT_MAX;
    
    for (const string& candidate : candidates) {
        if (candidate.empty()) {
            continue;
        }
        int candidateNum = stoi(candidate);
        if (candidateNum == originalNum) {
            continue;
        }
        int steps = abs(candidateNum - originalNum);
        if (steps < minSteps) {
            minSteps = steps;
        }
    }
    
    return minSteps;
}

int main() {
	int t;
	cin >> t;
	while(t--){
		int num; cin >> num;
		cout << solve(num) << endl;
	}
}