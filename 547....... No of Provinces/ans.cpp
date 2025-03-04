#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>> &isConnected, vector<bool> &visited, int &c) {
    visited[i] = true;
    c++;
    for (int j = 0; j < isConnected.size(); j++) {
        if (i != j && isConnected[i][j] == 1 && !visited[j]) {
            dfs(j, isConnected, visited, c);
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected, int k) {
    int cities = isConnected.size();
    vector<bool> visited(cities, false);
    int provinces = 0;

    for (int i = 0; i < cities; i++) {
        if (!visited[i]) {
            int c = 0;  
            dfs(i, isConnected, visited, c);
            if (c >= k)  
                provinces++;
        }
    }

    return provinces;
}

void solve() {
    int n,m, k;
    cin >> n >> m;
    vector<vector<int>> isConnected(n, vector<int>(m));

    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> isConnected[i][j];
        }
    }

    cin >> k;  
    cout << findCircleNum(isConnected, k) << endl;  
}

int main() {
    int t;
    cin >> t;  
    while (t--) {
        solve();  
    }
    return 0;
}

