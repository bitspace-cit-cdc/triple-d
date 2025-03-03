#include <bits/stdc++.h>
using namespace std;
int myfunc(int x) {
	if (x == 0) return 0;
	int left = 1, right = x;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (mid == x /( mid*mid)) {
			return mid;
		} else if (mid < x /(mid* mid)) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return right;
}

int main(){
	int n;
	cin>>n;
	cout<<myfunc(n)<<endl;
}