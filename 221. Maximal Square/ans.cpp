#include <bits/stdc++.h>
using namespace std;

void maximalSquare(vector<vector<char>>& matrix, vector<vector<int>>& dp) {
    int m = matrix.size(), n = matrix[0].size();
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = (1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}));
            }
        }
    }
}

int main() {
    int m, n, q;
    cin >> m >> n;
    
    vector<vector<char>> matrix(m, vector<char>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> dp(m, vector<int>(n, 0));

    maximalSquare(matrix, dp);
    
    cin >> q;
    vector<pair<int, int>> queries(q);
    
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    for (auto &i : queries) {
        cout << dp[i.first][i.second] << " ";
    }
    cout << endl;

    return 0;
}