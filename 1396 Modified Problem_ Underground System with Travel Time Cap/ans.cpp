#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem {
    unordered_map<int, pair<string, int>> checkIns;
    unordered_map<string, pair<long long, int>> travelData;
    int cap;
public:
    UndergroundSystem(int T) : cap(T) {}
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto info = checkIns[id];
        string startStation = info.first;
        int t0 = info.second;
        int travelTime = t - t0;
        if(travelTime <= cap) {
            string key = startStation + "->" + stationName;
            travelData[key].first += travelTime;
            travelData[key].second += 1;
        }
        checkIns.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "->" + endStation;
        if(travelData.find(key) == travelData.end() || travelData[key].second == 0)
            return -1.0;
        auto data = travelData[key];
        return (double)data.first / data.second;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int T;
        cin >> T;
        UndergroundSystem system(T);
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            string op;
            cin >> op;
            if(op=="checkIn"){
                int id, time;
                string station;
                cin >> id >> station >> time;
                system.checkIn(id, station, time);
            } else if(op=="checkOut"){
                int id, time;
                string station;
                cin >> id >> station >> time;
                system.checkOut(id, station, time);
            } else if(op=="getAverageTime"){
                string start, end;
                cin >> start >> end;
                double avg = system.getAverageTime(start, end);
                cout << fixed << setprecision(5) << avg << "\n";
            }
        }
    }
    return 0;
}