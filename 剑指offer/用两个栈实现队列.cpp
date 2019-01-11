#include <stack>
#include <iostream>

using namespace std;
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int val;
        val = stack2.top();
        stack2.pop();
        return val;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(){
    Solution s;
    s.push(1);
    s.push(3);
    std::cout<<s.pop()<<"  "<<s.pop()<<endl;

}