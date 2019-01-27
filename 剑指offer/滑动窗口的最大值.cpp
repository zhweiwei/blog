#include <vector>
#include <queue>


using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> Rvalue;

        if(num.size() == 0 || size == 0|| num.size() < size)
        return Rvalue;
        
        for(auto i = num.begin();i+size <= num.end();i++){
            auto p = i;
            int max = *p;
        while(p < i+size){
            if(*p > max)
            max = *p;
            p++;
            }
            Rvalue.push_back(max);
        }

        return Rvalue;
        
    }

};