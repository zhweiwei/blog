#include <iostream>

using namespace std;

class Solution{
    public:
    int printbinary(int a){
        int count = 0;

        while(a){
            count++;
            a = (a-1)&a;
        }
        return count;
    }
};

int main(){
    Solution s;
    cout <<s.printbinary(9)<<endl;
}