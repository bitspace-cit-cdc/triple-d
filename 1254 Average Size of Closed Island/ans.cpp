
#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
        return 0;
    grid[i][j] = 0;
    return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
}

double averageIslandSize(vector<vector<int>>& grid) {
    int totalSize = 0, count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                totalSize += dfs(grid, i, j);
                count++;
            }
        }
    }
    return count == 0 ? 0.0 : (double) totalSize / count;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    cout << fixed << setprecision(1) << averageIslandSize(grid) << "\n";
    return 0;
}
