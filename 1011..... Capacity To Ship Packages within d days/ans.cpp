#include <bits/stdc++.h>
using namespace std;
int daytaken(vector<int>& nums,int mid){
	int ndays=1;
	int left=mid;
	int c=0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i]+c > left) {
			ndays++;
			c++;
			left = mid - nums[i]-c;
			if(left<0) return INT_MAX;
		} else {
			left -= nums[i]-c;
		}
	}
	return ndays;
   
}

int shipWithinDays(vector<int>& weights, int days) {
	int n=weights.size();

	int low=*max_element(weights.begin(),weights.end());
	int high=accumulate(weights.begin(),weights.end(),0);
	int ans=-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		int nofdays=daytaken(weights,mid);
		if(nofdays<=days){
			 ans=mid;
			  high=mid-1;
		}
		else low=mid+1;
	}
	return ans;
	
}

int main() {
    int n, days;
    cin >> n >> days;

    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    cout << shipWithinDays(weights, days) << endl;
    return 0;
}