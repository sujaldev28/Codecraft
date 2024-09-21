#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void insertAtBottom(stack<int>& s, int item) {
    if (s.empty()) s.push(item);
    else {
        int top = s.top(); s.pop();
        insertAtBottom(s, item);
        s.push(top);
    }
}

void reverseStack(stack<int>& s) {
    if (!s.empty()) {
        int top = s.top(); s.pop();
        reverseStack(s);
        insertAtBottom(s, top);
    }
}

int main() {
    stack<int> s;
    int n, item;
    
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter stack elements: ";
    for (int i = 0; i < n; i++) {
        cin >> item;
        s.push(item);
    }

    reverseStack(s);
    
    cout << "Reversed stack: ";
    vector<int> reversed;
    while (!s.empty()) {
        reversed.push_back(s.top());
        s.pop();
    }
    
    for (int i = reversed.size() - 1; i >= 0; i--) {
        cout << reversed[i] << " ";
    }
    cout << endl;

    return 0;
}
