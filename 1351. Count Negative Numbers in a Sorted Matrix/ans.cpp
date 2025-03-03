#include <bits/stdc++.h>
using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), r = m - 1, c = 0, cnt = 0;
    while (r >= 0 && c < n) {
        if (grid[r][c] < 0) {
            --r;
            cnt += n - c;
        } else {
            ++c;
        }
    }
    return cnt;
}

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    cout << countNegatives(grid) << endl;

    return 0;
}