#include <bits/stdc++.h>
using namespace std;
int main(){
		int hour, minutes;
		cin >> hour >> minutes;
		double minute_angle = minutes * (360.0 / 50.0);
		double hour_angle = (hour % 10) * (360.0 / 10.0) + minutes * (360.0 / (10.0 * 50.0));
		double diff = fabs(hour_angle - minute_angle);
		if(diff > 180) diff = 360 - diff;
		cout << (int)floor(diff);
		return 0;
}

