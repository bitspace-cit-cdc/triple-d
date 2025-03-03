#include <bits/stdc++.h>
using namespace std;

vector<int> findJudges(int n, vector<vector<int>>& trust) {
	vector<int> inDegree(n + 1, 0);
	vector<int> outDegree(n + 1, 0);

	for (auto& t : trust) {
		int a = t[0], b = t[1];
		outDegree[a]++;
		inDegree[b]++;
	}

	vector<int> judges;
	for (int i = 1; i <= n; ++i) {
		if (inDegree[i] >= n/2 && outDegree[i] == 0) {
			judges.push_back(i);
		}
	}
	if (judges.size()==0) return {-1};
	return judges;
}


int main() {
    int n;
    cin>>n;
    vector<vector<int>> trust = {{1, 3}, {2, 3}, {4, 3}};
    vector<int> result = findJudges(n, trust);
    for (int x : result1) cout << x << " ";

    return 0;
}