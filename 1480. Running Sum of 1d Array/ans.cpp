#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    vector<int> result;
    int current_sum = 0;

    for (int num : nums) {
        current_sum += num;
		result.push_back(current_sum);
        if (current_sum < 0) {
            current_sum = 0;
        }
    }

    return result;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> result = runningSum(nums);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}