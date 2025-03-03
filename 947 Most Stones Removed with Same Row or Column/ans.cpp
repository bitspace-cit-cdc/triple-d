

#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    unordered_map<int, int> parent, rank;
    int components = 0;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr != yr) {
            if (rank[xr] > rank[yr]) swap(xr, yr);
            parent[xr] = yr;
            if (rank[xr] == rank[yr]) rank[yr]++;
            components--;
        }
    }
    
    void add(int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            rank[x] = 0;
            components++;
        }
    }
};

int maxStonesRemoved(vector<vector<int>>& stones) {
    DSU dsu;
    for (auto& s : stones) {
        dsu.add(s[0]);
        dsu.add(~s[1]);
        dsu.add(s[0] - s[1]);
        dsu.add(s[0] + s[1]);
        dsu.unite(s[0], ~s[1]);
        dsu.unite(s[0], s[0] - s[1]);
        dsu.unite(s[0], s[0] + s[1]);
    }
    return stones.size() - dsu.components;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> stones(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> stones[i][0] >> stones[i][1];
    cout << maxStonesRemoved(stones) << "\n";
}
