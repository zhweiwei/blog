#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty()){
            return false;
        }

        int len = 0;
        int length = array.size();
        int with = array[0].size() - 1;

        while(len < length && with >= 0){
            if(array[len][with] == target)
            return true;

            if(array[len][with] > target){
                with--;
                continue;
            }

            if(array[len][with] < target){
                len++;
                continue;
            }
        }
            
        return false;
    }
};