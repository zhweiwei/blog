#include <iostream>

using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0)
        return 0;
        if(n ==1 || n == 2)
        return 1;

        int f[n+1];
            f[0] = 0;
            f[1] = 1;
        for(int i = 2 ;i <= n;i++){
            f[i] = f[i-1] + f[i-2];
        }

        return f[n];

    }
};

int main(){
    Solution s;
    
    cout<<s.Fibonacci(23)<<endl;
}