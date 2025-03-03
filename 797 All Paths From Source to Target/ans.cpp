
#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& res, int cur, int edges, int k) {
    path.push_back(cur);
    if (cur == graph.size() - 1) {
        if (edges <= k) res.push_back(path);
    }
    if (edges < k) {
        for (auto nxt : graph[cur]) {
            dfs(graph, path, res, nxt, edges + 1, k);
        }
    }
    path.pop_back();
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int num;
        while (ss >> num) graph[i].push_back(num);
    }
    int k;
    cin >> k;
    vector<vector<int>> res;
    vector<int> path;
    dfs(graph, path, res, 0, 0, k);
    for (auto& v : res) {
        for (size_t i = 0; i < v.size(); i++) {
            cout << v[i] << (i + 1 < v.size() ? " " : "");
        }
        cout << "\n";
    }
    return 0;
}
