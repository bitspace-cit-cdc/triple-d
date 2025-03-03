#include <iostream>
using namespace std;

int integerBreak(int n) {
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;

    int n3 = n / 3;
    int rem = n % 3;

    if (rem == 1) {
        rem = 4;
        n3--;
    } else if (rem == 0)
        rem = 1;

    long long c = 1;
    for (int i = 1; i <= n3; i++) {
        c = (c * 3) % 1000000007;
    }

    return (c * rem) % 1000000007;
}

int main() {
    int n;
    cin >> n;
    
    int result = integerBreak(n);
    cout << result << endl;
    
    return 0;
}