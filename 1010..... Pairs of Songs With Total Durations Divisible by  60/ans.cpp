#include <bits/stdc++.h>
using namespace std;

int numPairs(int n,vector<int>& time) {

	vector<int>v(60,0),v1(50,0),v2(300,0);
	
	int ans=0;
	
	for(int i=time.size()-1;i>-1;i--){
	
		ans+=v[(60-time[i]%60)%60];
		
		v[time[i]%60]++;
		
		ans+=v1[(50-time[i]%50)%50];
		
		v1[time[i]%50]++;
		
		ans-=v2[(300-time[i]%300)%300];
		
		v2[time[i]%300]++;
	
	}
	
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	cout<< numPairs(n,v)<<endl;
	return 0;
}