#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {

        if(array.size() == 0)
        return 0;

        vector<int> tmp;
        for(int i = 0;i <array.size();i++){
            if(tmp.size() == 0){
                tmp.push_back(array[i]);
                continue;
            }
          if(tmp.back() >= 0){
              tmp.push_back(tmp.back() + array[i]);
              continue;
          }else{
              tmp.push_back(array[i]);
          }  
        }

        int max = tmp.front();
        for(int i = 0;i < tmp.size();i++){
            if(tmp[i] > max)
            max = tmp[i];
        }

        return max;
    }
};