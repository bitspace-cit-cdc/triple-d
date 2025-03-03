#include <bits/stdc++.h>
using namespace std;

vector<bool> check(vector<string>& dic,vector<string>& words){
	vector<bool>ans;
	for(string order:dic){
		map<char,char>orders;
		
		int j=0;
		
		for(auto i:order){
		
			orders[i]=j+'a';
			
			j++;
		
		}
		
		vector<string>word,w1;
		
		for(auto i:words){
			string s;
			
			for(auto j:i){
				s+=orders[j];
			}
			
			word.push_back(s);
			w1.push_back(s);	
		}
		
		sort(w1.begin(),w1.end());
		
		ans.push_back( w1==word);
	}
	return ans;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<string>dic(n),words(m);
	for(int i=0;i<n;i++){
		cin>>words[i];
	}
	for(int i=0;i<n;i++){
		cin>>dic[i];
	}
	vector<bool>ans=check(dic,words);
	for(auto i:ans) cout<<i<<" ";
	cout<<endl;
}