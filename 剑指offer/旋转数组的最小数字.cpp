#include <vector>

using namespace std;
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        
        if(rotateArray.empty())
        return 0;

        int l = 0;
        int h = rotateArray.size();

        int tmp = rotateArray[0];
        int m;
        while(l < h){
            m = l + (h-l)/2;
            if(tmp < rotateArray[m]){
                l = m+1;
                continue;
            }
            else{
                tmp = rotateArray[m];
                h = m;
            }
        }
        return tmp;
    }
};


int main(){
    Solution s;
}