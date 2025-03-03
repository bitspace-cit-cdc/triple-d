
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    bool hasLand = false, hasWater = false;
    vector<pair<int,int>> lands;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                hasLand = true;
                lands.push_back({i, j});
            } else {
                hasWater = true;
            }
        }
    }
    if(!hasLand || !hasWater){
        cout << -1;
        return 0;
    }
    long long min_u = LLONG_MAX, max_u = LLONG_MIN, min_v = LLONG_MAX, max_v = LLONG_MIN;
    for(auto &p : lands){
        int x = p.first, y = p.second;
        long long u = x + y, v = x - y;
        min_u = min(min_u, u);
        max_u = max(max_u, u);
        min_v = min(min_v, v);
        max_v = max(max_v, v);
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(grid[i][j] == 0){
                long long u = i + j, v = i - j;
                long long cand1 = max(u - min_u, max_u - u);
                long long cand2 = max(v - min_v, max_v - v);
                int cand = (int)max(cand1, cand2);
                ans = min(ans, cand);
            }
        }
    }
    cout << ans;
    return 0;
}
