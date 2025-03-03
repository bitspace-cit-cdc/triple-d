#include <bits/stdc++.h>
using namespace std;

vector<int> generate(int numRows) {
    vector<vector<int>> result;

    for (int row = 0; row < numRows; ++row) {
        vector<int> current_row(row + 1, 1);

        for (int i = 1; i < row; ++i) {
            current_row[i] = result[row - 1][i - 1] + result[row - 1][i];
        }

        result.push_back(current_row);
    }

    vector<int> flattened;
    for (const auto& row : result) {
        for (int num : row) {
            flattened.push_back(num);
        }
    }

    return flattened;
}

int main() {
    int numRows;
    cin >> numRows;

    vector<int> flattened = generate(numRows);

    for (int num : flattened) {
        cout << num << " ";
    }

    return 0;
}