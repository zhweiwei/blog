#include <vector>
#include <cstddef>
#include <iostream>

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
        return false;
        return test(sequence,0,sequence.size() -1);

    }

    int partition(vector<int> val,int begin,int end){
        int pos;
        while(begin < end){
            if(val[begin] >val[end] )
            return begin;

            begin++;
        }

        return begin;
    }

    bool test(vector<int> val,int begin,int end){
        if(begin >= end)
        return true;
 //       int flag = 0;
        while(begin < end){
            if(val[begin] > val[end]){
                break;
            }
            begin++;
        }

        while(begin  < end){
            if(val[begin] <= val[end])
            return false;

            begin++;
        }

        int pos = partition(val,begin,end);

        return test(val,begin,pos -1 ) && test(val,pos,end-1);
    }
};


int main(){
    vector<int> a = {1,4,3};

    Solution s;
    cout << s.VerifySquenceOfBST(a);
}