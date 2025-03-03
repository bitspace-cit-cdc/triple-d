#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int i = 0, n = s.length();
    
    while (i < n && s[i] == ' ') {
        i++;
    }
    
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    
    if (i < n && s[i] == '0' && (i + 1 < n && (s[i + 1] == 'x' || s[i + 1] == 'X'))) {
        i += 2;
        long hex_value = 0;
        while (i < n && ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'))) {
            hex_value = hex_value * 16 + (s[i] >= '0' && s[i] <= '9' ? s[i] - '0' : (s[i] >= 'a' && s[i] <= 'f') ? s[i] - 'a' + 10 : s[i] - 'A' + 10);
            i++;
        }
        return static_cast<int>(sign * hex_value);
    }
    
    long result = 0;
    while (i < n && s[i] >= '0' && s[i] <= '9') {
        result = result * 10 + (s[i] - '0');
        i++;
    }
    
    result *= sign;
    
    if (result < INT_MIN) {
        return static_cast<int>(INT_MIN);
    }
    if (result > INT_MAX) {
        return static_cast<int>(INT_MAX);
    }
    
    return static_cast<int>(result);
}

int main() {
    string s;
    getline(cin, s); 
    cout << myAtoi(s) << endl;
    return 0;
}