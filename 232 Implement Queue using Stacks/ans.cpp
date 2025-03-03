
#include <bits/stdc++.h>
using namespace std;
class MyQueue {
    stack<int> inStack, outStack;
    int totalSum;
public:
    MyQueue(): totalSum(0) {}
    void push(int x) {
        inStack.push(x);
        totalSum += x;
    }
    int pop() {
        if(outStack.empty()){
            while(!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int x = outStack.top();
        outStack.pop();
        totalSum -= x;
        return x;
    }
    int peek() {
        if(outStack.empty()){
            while(!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
    int size() {
        return inStack.size() + outStack.size();
    }
    int sum() {
        return totalSum;
    }
};
int main(){
    int n;
    cin >> n;
    vector<string> commands(n);
    for(int i=0;i<n;i++){
        cin >> commands[i];
    }
    vector<int> args;
    for (int i = 0; i < n; i++){
        if(commands[i]!="MyQueue" && commands[i]=="push"){
            int x; cin >> x;
            args.push_back(x);
        }
    }
    MyQueue mq;
    int argIndex = 0;
    for (int i = 0; i < n; i++){
        if(commands[i]=="MyQueue"){
            cout << "null" << "\n";
        } else if(commands[i]=="push"){
            mq.push(args[argIndex++]);
            cout << "null" << "\n";
        } else if(commands[i]=="pop"){
            cout << mq.pop() << "\n";
        } else if(commands[i]=="peek"){
            cout << mq.peek() << "\n";
        } else if(commands[i]=="empty"){
            cout << (mq.empty() ? "true" : "false") << "\n";
        } else if(commands[i]=="size"){
            cout << mq.size() << "\n";
        } else if(commands[i]=="sum"){
            cout << mq.sum() << "\n";
        } else {
            cout << "null" << "\n";
        }
    }
    return 0;
}
