#include <bits/stdc++.h>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
    bool working;
};

void DFS(unordered_map<int, Employee*>& m, int id, int& sum) {
    if(m[id]->working) sum += m[id]->importance;
    for(auto x: m[id]->subordinates) DFS(m, x, sum);
}

int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int, Employee*> m;
    for(auto x: employees) m[x->id] = x;
    int sum = 0;
    DFS(m, id, sum);
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<Employee*> employees(n);

    for(int i = 0; i < n; ++i) {
        int id, importance, numSubordinates;
        bool working;
        cin >> id >> importance >> working >> numSubordinates;

        Employee* emp = new Employee();
        emp->id = id;
        emp->importance = importance;
        emp->working = working;

        for(int j = 0; j < numSubordinates; ++j) {
            int subId;
            cin >> subId;
            emp->subordinates.push_back(subId);
        }
        employees[i] = emp;
    }

    int id;
    cin >> id;

    cout << getImportance(employees, id) << endl;

    return 0;
}