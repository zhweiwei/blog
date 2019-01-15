#include <iostream>
#include <cstring>

using namespace std;

class Solution{
    public:
    void printoneTon(int n){
        if(n <= 0)
        return; 

        char stor[n+1];
        memset(stor,'0',n+1);
        stor[n]  = '\0';
        while(Increment(stor,n)){
            printNumber(stor);
        }

    }

    bool Increment(char * number,int n){
        while(n > 0){
            if(number[n-1] != '9'){
                number[n-1] = number[n-1]+1 ;
                return true;
            }else{
                number[n-1] = '0';
                n--;
            }      
        }
        return false;
    }

    void printNumber(char *number){
            char *tmp = number;
            while(*tmp == '0')
            tmp++;
            cout << tmp<<" ";
    }
};


int main(){
    Solution s;
    s.printoneTon(10);
}