#include <bits/stdc++.h>
using namespace std;

string removeLeadingZeros(string s) {
    int i = 0;
    while (i < s.size() && s[i] == '0') i++;
    return i == s.size() ? "0" : s.substr(i);
}

string subtractBinary(string a, string b) {
    if (a.length() < b.length() || (a.length() == b.length() && a < b)) 
        swap(a, b);
    string result = "";
    int carry = 0, i = a.length() - 1, j = b.length() - 1;
    while (i >= 0) {
        int bitA = a[i--] - '0';
        int bitB = j >= 0 ? b[j--] - '0' : 0;
        int diff = bitA - bitB - carry;
        if (diff < 0) {
            diff += 2;
            carry = 1;
        } else {
            carry = 0;
        }
        result += (diff + '0');
    }
    reverse(result.begin(), result.end());
    return removeLeadingZeros(result);
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << subtractBinary(a, b) << endl;
    return 0;
}