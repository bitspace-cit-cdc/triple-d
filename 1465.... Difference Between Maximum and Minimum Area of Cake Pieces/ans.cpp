
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long h, w;
    cin >> h >> w;
    int n, m;
    cin >> n >> m;
    vector<long long> horizontal(n), vertical(m);
    for (int i = 0; i < n; i++){
        cin >> horizontal[i];
    }
    for (int j = 0; j < m; j++){
        cin >> vertical[j];
    }
    sort(horizontal.begin(), horizontal.end());
    sort(vertical.begin(), vertical.end());
    long long max_h = max(horizontal[0], h - horizontal.back());
    long long min_h = min(horizontal[0], h - horizontal.back());
    for (int i = 1; i < n; i++){
        long long diff = horizontal[i] - horizontal[i - 1];
        max_h = max(max_h, diff);
        min_h = min(min_h, diff);
    }
    long long max_v = max(vertical[0], w - vertical.back());
    long long min_v = min(vertical[0], w - vertical.back());
    for (int j = 1; j < m; j++){
        long long diff = vertical[j] - vertical[j - 1];
        max_v = max(max_v, diff);
        min_v = min(min_v, diff);
    }
    const long long mod = 1000000007;
    long long max_area = ((max_h % mod) * (max_v % mod)) % mod;
    long long min_area = ((min_h % mod) * (min_v % mod)) % mod;
    long long ans = (max_area - min_area + mod) % mod;
    cout << ans;
    return 0;
}
