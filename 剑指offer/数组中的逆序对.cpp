#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    long int InversePairs(vector<int> data) {
        if(data.size() == 0)
        return 0;

        long int count = devide(data,0,data.size()-1);
        return count%1000000007;
    }

    long int devide(vector<int> &data, int first, int end){
        long int count = 0;
        if(first < end){
              int min = first + (end-first)/2;
            count += devide(data,first,min);
            count += devide (data,min+1,end);

            count += mergin(data,first,min,end);

        }

        return count;
    }

    long int mergin(vector<int> &data,int first ,int min,int end){
        vector<int> tmp{} ;
        long int count =0;

        int i = first;
        int j = min+1;

        while(i <= min && j<= end){
            if(data[i] <= data[j]){
                tmp.push_back(data[i]);
                i++;
                continue;
            }else{
                tmp.push_back(data[j]);
                j++;
                count += min - i + 1;
            }
        }

        while(i <= min ){
        tmp.push_back(data[i]);
        i++;
        }

        while(j <= end){
        tmp.push_back(data[j]);
        j++;
        }

        for(i = 0,j = first;j <= end;i++,j++){
            data[j] = tmp[i];
        }

        return count;
    }
};


int main(){
    vector<int> data = {5,6,7,0};
    Solution s;
    cout <<s.InversePairs(data);

}