
#include <bits/stdc++.h>
using namespace std;
 
int n, headID;
vector<int> manager, informTime;
vector<vector<int>> children;
 
int dfs(int node) {
    if(children[node].empty())
        return 0;
    int maxSub = 0;
    for (int child : children[node]) {
        maxSub = max(maxSub, dfs(child));
    }
    return informTime[node] + maxSub;
}
 
int main(){
    freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
    cin >> n >> headID;
    manager.resize(n);
    informTime.resize(n);
    children.resize(n);
    for (int i = 0; i < n; i++){
        cin >> manager[i];
    }
    for (int i = 0; i < n; i++){
        cin >> informTime[i];
    }
    
    for (int i = 0; i < n; i++){
        if(manager[i] != -1)
            children[manager[i]].push_back(i);
    }
    
    int maxInformSum = dfs(headID);
    cout << 2LL * maxInformSum;
    return 0;
}
