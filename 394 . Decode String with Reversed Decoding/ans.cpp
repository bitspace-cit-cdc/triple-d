#include <bits/stdc++.h>
using namespace std;

string decodeString(string s) {
	stack<char> st;
	int c = 0;
	string s1, t, t1, t2;
	for (auto i : s) {
		if (i == '[')
			c++;
		if (i == ']')
			c--;
		if(c==0 and i!=']' and i!='[' and !isdigit(i)) s1+=i;
		else if (i == ']') {
			while (!st.empty() and st.top() != '[') {
				t += st.top();
				st.pop();
			}
			int n = 0;
			st.pop();
			while (!st.empty() and isdigit(st.top())) {
				t1 += st.top();
				st.pop();
			}
			if (t1.size() == 1)
				n = stoi(t1.c_str());
			else
				n = stoi(t1);
			while (n--) {
				t2 += t;
			}
			n = 0;
			if (c) {
				for (auto j : t2)
					st.push(j);
			} else
				s1 += t2;
			t1 = "";
			t2 = "";
			t = "";
		} else {
			st.push(i);
		}
	}
	return s1;
}

int main(){
	string s;
	cin>>s;
	cout<<decodeString(s)<<endl;
	return 0;
}