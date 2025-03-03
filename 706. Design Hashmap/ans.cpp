
#include <bits/stdc++.h>
using namespace std;
class MyHashMap {
    static const int BUCKET_SIZE = 10007;
    vector<list<pair<int, pair<vector<int>, long long>>>> buckets;
public:
    MyHashMap() : buckets(BUCKET_SIZE) {}
    void put(int key, vector<int>& value) {
        int idx = key % BUCKET_SIZE;
        for(auto it = buckets[idx].begin(); it != buckets[idx].end(); ++it) {
            if(it->first == key) {
                long long s = 0;
                for (int num : value) s += num;
                it->second = {value, s};
                return;
            }
        }
        long long s = 0;
        for (int num : value) s += num;
        buckets[idx].push_back({key, {value, s}});
    }
    int get_sum(int key) {
        int idx = key % BUCKET_SIZE;
        for(auto &entry : buckets[idx]) {
            if(entry.first == key) return (int)entry.second.second;
        }
        return -1;
    }
    void remove(int key) {
        int idx = key % BUCKET_SIZE;
        for(auto it = buckets[idx].begin(); it != buckets[idx].end(); ++it) {
            if(it->first == key) { buckets[idx].erase(it); return; }
        }
    }
};
int main(){
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    vector<string> ops(q);
    for (int i = 0; i < q; i++) cin >> ops[i];
    MyHashMap mp;
    for (int i = 0; i < q; i++){
        if(ops[i]=="MyHashMap"){
        } else if(ops[i]=="put"){
            int key, len;
            cin >> key >> len;
            vector<int> arr(len);
            for (int j = 0; j < len; j++) cin >> arr[j];
            mp.put(key, arr);
        } else if(ops[i]=="get_sum"){
            int key;
            cin >> key;
            cout << mp.get_sum(key) << "\n";
        } else if(ops[i]=="remove"){
            int key;
            cin >> key;
            mp.remove(key);
        }
    }
    return 0;
}
