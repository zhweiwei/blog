#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.empty())
        return;

        int size = array.size();
        int i,j ,tmp;
        for( i = 0;i < size;i++){
            if(array[i]%2 == 1){
                tmp = array[i];
                for(j = i;j-1>=0;j--){
                    if(array[j-1]%2 == 1)
                    break;
                    array[j] = array[j-1];
                }
                array[j] = tmp;
            }
        }
    }
};