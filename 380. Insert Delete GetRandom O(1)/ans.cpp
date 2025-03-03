
#include <bits/stdc++.h>
using namespace std;
class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int,int> mp;
    int n = 0, sum = 0;
    RandomizedSet() {}
    bool insert(int val) {
        if(mp[val] != 0) return false;
        v.push_back(val);
        n++;
        mp[val] = n;
        sum += val;
        return true;
    }
    bool remove(int val) {
        if(!mp[val]) return false;
        int x = v[n - 1], y = mp[val];
        swap(v[n - 1], v[mp[val] - 1]);
        mp[x] = y;
        v.pop_back();
        sum -= val;
        n--;
        mp[val] = 0;
        return true;
    }
    int getRandom() {
        return v[rand() % n];
    }
    int getSum() {
        return sum;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<string> ops(t);
    for(int i = 0; i < t; i++){
        cin >> ops[i];
    }
    RandomizedSet rs;
    for(auto &op : ops){
        if(op == "RandomizedSet"){
            cout << "null" << "\n";
        }
        else if(op == "insert"){
            int x;
            cin >> x;
            cout << (rs.insert(x) ? "true" : "false") << "\n";
        }
        else if(op == "remove"){
            int x;
            cin >> x;
            cout << (rs.remove(x) ? "true" : "false") << "\n";
        }
        else if(op == "getRandom"){
            cout << rs.getRandom() << "\n";
        }
        else if(op == "getSum"){
            cout << rs.getSum() << "\n";
        }
    }
    return 0;
}
