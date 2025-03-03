#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BrowserHistory {
public:
    struct Node{
        string data;
        struct Node* prev, *next; 
    };
    Node* head = new Node();
    
    BrowserHistory(string homepage) {
        head->data = homepage; 
    }
    
    void visit(string url) {
        Node* node = new Node();
        node->data = url;
        if (head->next) head->next->prev = nullptr;
        node->prev = head;
        head->next = node;
        head = node;
    }
    
    string back(int steps) {
        while (head->prev && steps--) head = head->prev;
        return head->data;
    }
    
    string forward(int steps) {
        while (head->next && steps--) head = head->next;
        return head->data;
    }
    
    void deleteUrl() {
        if (!head->prev) return;
        if (head->next) {
            head->next->prev = head->prev;
            head->prev->next = head->next;
            head = head->prev;
        }
    }
};

int main() {
    vector<string> operations;
    vector<vector<string>> params;

    int n;
    cin >> n;
    operations.resize(n);
    params.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> operations[i];
        int paramCount;
        cin >> paramCount;
        params[i].resize(paramCount);
        for (int j = 0; j < paramCount; j++) {
            cin >> params[i][j];
        }
    }

    BrowserHistory* obj = nullptr;
    vector<string> result;

    for (int i = 0; i < operations.size(); i++) {
        if (operations[i] == "BrowserHistory") {
            obj = new BrowserHistory(params[i][0]);
            result.push_back("null");
        }
        else if (operations[i] == "visit") {
            obj->visit(params[i][0]);
            result.push_back("null");
        }
        else if (operations[i] == "back") {
            int steps = stoi(params[i][0]);
            result.push_back(obj->back(steps));
        }
        else if (operations[i] == "forward") {
            int steps = stoi(params[i][0]);
            result.push_back(obj->forward(steps));
        }
        else if (operations[i] == "delete") {
            obj->deleteUrl();
            result.push_back("null");
        }
    }

    for (const string& res : result) {
        cout << res << endl;
    }

    return 0;
}