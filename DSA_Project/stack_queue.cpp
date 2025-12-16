// Stack and Queue Algorithms Implementation
#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

// Balanced Parentheses - O(n) time, O(n) space
bool isBalanced(string str) {
    stack<char> s;

    for (char ch : str) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty()) return false;

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }
    return s.empty();
}

// Queue using Two Stacks - O(1) amortized
class QueueUsingStacks {
private:
    stack<int> s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (s2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        int val = s2.top();
        s2.pop();
        return val;
    }
};
