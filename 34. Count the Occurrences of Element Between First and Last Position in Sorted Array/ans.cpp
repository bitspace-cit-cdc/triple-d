#include <bits/stdc++.h>
using namespace std;

int searchRange(vector<int>& nums, int target) {
	int startingPosition = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
	int endingPosition = lower_bound(nums.begin(), nums.end(), target+1) - nums.begin() - 1;
	if(startingPosition < nums.size() && nums[startingPosition] == target){
		return  endingPosition - startingPosition + 1;
	}
	return 0;
}

int main(){
	int n,k;
	cin >> n >> k;
	vector<int>nums(n);
	for(int i=0;i<n;i++){
		cin >> nums[i];
	}
	cout << searchRange(nums,k) << endl;
}