
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long x, y;
    cin >> x >> y >> n;
    if(n == 0){
        cout << x;
        return 0;
    }
    long long F_next = y, F_curr = x, F_prev;
    for(int i = n; i >= 1; i--){
        F_prev = F_next - F_curr;
        F_next = F_curr;
        F_curr = F_prev;
    }
    cout << F_curr;
    return 0;
}
