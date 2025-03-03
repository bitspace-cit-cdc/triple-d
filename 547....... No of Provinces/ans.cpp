#include <bits/stdc++.h>
using namespace std;

int c=0;
void dfs(int i, vector<vector<int>>& isConnected, vector<bool>& visited) {
	c++;
	visited[i]=true;
	for(int j=0;j<isConnected.size();j++){
		if(i!=j && isConnected[i][j]==true && visited[j]==false){
			dfs(j,isConnected,visited);
		}
	}
}
int findCircleNum(vector<vector<int>>& isConnected, int k) {

	int cities= isConnected.size();
	vector<bool> visited(cities, false);
	int provinces=0;

	for(int i=0;i<cities;i++){
		if(visited[i]==false){
			c=0;
			dfs(i,isConnected,visited);
			if(c>k)
			provinces++;
		}
	}

	return provinces;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> isConnected(n, vector<int>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> isConnected[i][j];
        }
    }
	cout<< findProvinces(isConnected,k)<<endl;
    return 0;
}