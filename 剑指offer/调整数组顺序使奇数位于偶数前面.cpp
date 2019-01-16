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
            while(i <size && Comp(array[i]))
            i++;
            j = i+1;
            while(j< size&& !Comp(array[j]))
            j++;

            if( i < size && j < size){
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }           
        }
    }

    bool Comp(int val){
        return val %2;
    }
};

int main(){
    vector<int> a = {2,4,3,1,5,6,4,7};
    Solution s;
    s.reOrderArray(a);
    for(auto val:a)
    cout<<val<<" ";
    cout <<endl;
}