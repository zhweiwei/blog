#include <iostream>

using namespace std;

class Solution{
    public:
    int printbinary(int a){
        if(a < 0)
        return 0;
        int count = 0;
        int i = 0;
        
        while(a){
            if(i = a%2)
            count++;
            a = a>>1;
        }
        return count;
    }
};

int main(){
    Solution s;
    cout <<s.printbinary(9)<<endl;
}