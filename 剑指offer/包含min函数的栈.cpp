#include <cstddef>
#include <vector>
#include <stack>

using namespace std;

stack<int> m,n;

class Solution {
stack<int> m,n;

public:
    void push(int value) {
        if(m.empty()){
            m.push(value);
            n.push(value);
            return;
        }

        m.push(value);
        if(value < n.top())
        n.push(value);
        else
        n.push(n.top());

    }
    void pop() {
        m.pop();
        n.pop();
    }
    int top() {
      return  m.top();
    }
    int min() {
      return  n.top();
    }
};