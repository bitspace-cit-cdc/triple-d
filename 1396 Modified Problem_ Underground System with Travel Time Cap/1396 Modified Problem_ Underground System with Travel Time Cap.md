## Modified Problem: Underground System with Travel Time Cap

An underground railway system tracks customer travel times between different stations. In this modified version, the system is initialized with a travel time cap `T`. Only journeys with a travel time **less than or equal to** `T` are recorded and considered when computing average travel times. Any journey with a travel time exceeding `T` is ignored. Implement the UndergroundSystem class with the following methods:

- **UndergroundSystem(int T)**  
    Initializes the system with a travel time cap `T`.
    
- **void checkIn(int id, string stationName, int t)**  
    A customer with card ID `id` checks in at station `stationName` at time `t`.
    
- **void checkOut(int id, string stationName, int t)**  
    A customer with card ID `id` checks out from station `stationName` at time `t`.  
    Only if the travel time (t - check-in time) is less than or equal to `T`, record the journey from the check-in station to `stationName`.
    
- **double getAverageTime(string startStation, string endStation)**  
    Returns the average time for all recorded journeys from `startStation` to `endStation`.  
    If no journey was recorded for the given pair, return **-1.0**.
    

All calls to **checkIn** and **checkOut** are consistent (i.e. t1 < t2 for a given journey), and events occur in chronological order.

---

### Example 1

```
Input:
T = 15
Operations:
checkIn(45, "Leyton", 3)
checkIn(32, "Paradise", 8)
checkIn(27, "Leyton", 10)
checkOut(45, "Waterloo", 15)   // Travel time = 12 (recorded)
checkOut(27, "Waterloo", 20)   // Travel time = 10 (recorded)
checkOut(32, "Cambridge", 22)  // Travel time = 14 (recorded)
getAverageTime("Paradise", "Cambridge")  // returns 14.00000
getAverageTime("Leyton", "Waterloo")       // returns 11.00000
checkIn(10, "Leyton", 24)
checkOut(10, "Waterloo", 38)   // Travel time = 14 (recorded)
getAverageTime("Leyton", "Waterloo")       // returns 12.00000

Output:
14.00000
11.00000
12.00000
```

---

### Example 2

```
Input:
T = 10
Operations:
checkIn(10, "Leyton", 3)
checkOut(10, "Paradise", 8)   // Travel time = 5 (recorded)
getAverageTime("Leyton", "Paradise")  // returns 5.00000
checkIn(5, "Leyton", 10)
checkOut(5, "Paradise", 16)   // Travel time = 6 (recorded)
getAverageTime("Leyton", "Paradise")  // returns 5.50000
checkIn(2, "Leyton", 21)
checkOut(2, "Paradise", 30)   // Travel time = 9 (recorded)
getAverageTime("Leyton", "Paradise")  // returns 6.66667

Output:
5.00000
5.50000
6.66667
```

---

### Example 3

```
Input:
T = 10
Operations:
checkIn(1, "A", 5)
checkOut(1, "B", 20)    // Travel time = 15 (ignored, exceeds cap)
getAverageTime("A", "B") // returns -1.00000 (no valid journeys)
checkIn(2, "A", 10)
checkOut(2, "B", 15)    // Travel time = 5 (recorded)
getAverageTime("A", "B") // returns 5.00000

Output:
-1.00000
5.00000
```

---

## C++ Solution

```cpp
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
```

---

## Python Solution

```python
class UndergroundSystem:
    def __init__(self, T: int):
        self.cap = T
        self.checkIns = {}
        self.travelData = {}
    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.checkIns[id] = (stationName, t)
    def checkOut(self, id: int, stationName: str, t: int) -> None:
        startStation, t0 = self.checkIns.pop(id)
        travelTime = t - t0
        if travelTime <= self.cap:
            key = startStation + "->" + stationName
            if key not in self.travelData:
                self.travelData[key] = [0, 0]
            self.travelData[key][0] += travelTime
            self.travelData[key][1] += 1
    def getAverageTime(self, startStation: str, endStation: str) -> float:
        key = startStation + "->" + endStation
        if key not in self.travelData or self.travelData[key][1] == 0:
            return -1.0
        total, count = self.travelData[key]
        return total / count

if __name__ == '__main__':
    import sys
    input_data = sys.stdin.read().split()
    idx = 0
    t = int(input_data[idx]); idx += 1
    outputs = []
    for _ in range(t):
        T = int(input_data[idx]); idx += 1
        system = UndergroundSystem(T)
        n = int(input_data[idx]); idx += 1
        for i in range(n):
            op = input_data[idx]; idx += 1
            if op == "checkIn":
                id = int(input_data[idx]); idx += 1
                station = input_data[idx]; idx += 1
                time = int(input_data[idx]); idx += 1
                system.checkIn(id, station, time)
            elif op == "checkOut":
                id = int(input_data[idx]); idx += 1
                station = input_data[idx]; idx += 1
                time = int(input_data[idx]); idx += 1
                system.checkOut(id, station, time)
            elif op == "getAverageTime":
                start = input_data[idx]; idx += 1
                end = input_data[idx]; idx += 1
                avg = system.getAverageTime(start, end)
                outputs.append(f"{avg:.5f}")
    sys.stdout.write("\n".join(outputs))
```

---
