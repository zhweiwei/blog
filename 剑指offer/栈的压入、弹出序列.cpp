#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
stack<int> tmp;
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int size = pushV.size();
        int j = 0;
        for(int i = 0 ;i < size;i++){
                tmp.push(pushV[i]);

                while(j <size && tmp.top()== popV[j]){
                    tmp.pop();
                    j++;
                }
        }

        if(tmp.empty())
        return true;
        else
        return false;
    }
};

int main(){
    vector<int> pushV ={1,2,3,4,5};
    vector<int> popV =  {4,5,3,2,1};

    Solution s;
   cout<< s.IsPopOrder(pushV,popV)<<endl;
}