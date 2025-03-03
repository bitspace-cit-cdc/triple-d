
#include <bits/stdc++.h>
using namespace std;

string removeMin(string num, int k) {
    vector<char> st;
    for (char c : num) {
        while (!st.empty() && k > 0 && st.back() > c) {
            st.pop_back();
            k--;
        }
        st.push_back(c);
    }
    while (k-- > 0 && !st.empty())
        st.pop_back();
    string res(st.begin(), st.end());
    int i = 0;
    while (i < res.size() && res[i] == '0')
        i++;
    res = (i == res.size() ? "0" : res.substr(i));
	cout << res << endl;
    return res;
}

string removeMax(string num, int k) {
    vector<char> st;
    for (char c : num) {
        while (!st.empty() && k > 0 && st.back() < c) {
            st.pop_back();
            k--;
        }
        st.push_back(c);
    }
    while (k-- > 0 && !st.empty())
        st.pop_back();
    string res(st.begin(), st.end());
    int i = 0;
    while (i < res.size() && res[i] == '0')
        i++;
    res = (i == res.size() ? "0" : res.substr(i));
	cout << res << endl;
    return res;
}

int compareBig(const string &a, const string &b) {
    if(a.size() != b.size())
        return a.size() < b.size() ? -1 : 1;
    if(a == b) return 0;
    return (a < b) ? -1 : 1;
}

string subtract(string a, string b) {
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    string res;
    while(i >= 0 || j >= 0) {
        int da = i >= 0 ? a[i] - '0' : 0;
        int db = j >= 0 ? b[j] - '0' : 0;
        int sub = da - db - carry;
        if(sub < 0) { sub += 10; carry = 1; } else { carry = 0; }
        res.push_back(sub + '0');
        i--; j--;
    }
    reverse(res.begin(), res.end());
    int idx = 0;
    while(idx < res.size() && res[idx]=='0') idx++;
    res = (idx == res.size() ? "0" : res.substr(idx));
    return res;
}

int main(){
    string num;
    int k;
    cin >> num >> k;
    string minNum = removeMin(num, k);
    string maxNum = removeMax(num, k);
    string big, small;
    if(compareBig(maxNum, minNum) >= 0){
        big = maxNum;
        small = minNum;
    } else {
        big = minNum;
        small = maxNum;
    }
    string diff = subtract(big, small);
    cout << diff;
    return 0;
}
