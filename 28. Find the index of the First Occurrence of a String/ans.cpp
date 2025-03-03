#include <bits/stdc++.h>
using namespace std;

int indexOfFirstAndLastOccurrence(string haystack, string needle) {
    int firstIndex = haystack.find(needle);
    if (firstIndex == string::npos) {
        return -1;  
    }

    int lastIndex = haystack.rfind(needle);
    return firstIndex + lastIndex; 
}

int main() {
    string haystack, needle;
    cin >> haystack >> needle;

    cout << indexOfFirstAndLastOccurrence(haystack, needle) << endl;

    return 0;
}