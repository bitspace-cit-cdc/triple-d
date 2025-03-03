#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> visited = vector<int>(1000, 0);
int c = 0;

void dfs(int i, vector<vector<int>>& rooms) {
    c++;
    visited[i] = 1;
    for (auto j : rooms[i]) {
        if (!visited[j])
            dfs(j, rooms);
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    dfs(0, rooms);
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            dfs(i, rooms);
            break;
        }
    }
    return c == rooms.size();
}

int main() {
    cin >> n;

    vector<vector<int>> rooms(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        rooms[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> rooms[i][j];
        }
    }

    if (canVisitAllRooms(rooms)) {
        cout << true << endl;
    } else {
        cout << false << endl;
    }

    return 0;
}