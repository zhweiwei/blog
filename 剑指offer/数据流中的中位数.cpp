#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> store;
public:
    void Insert(int num)
    {
        store.push_back(num);
    }

    double GetMedian()
    { 
    sort(store.begin(),store.end());

    if(store.size() == 0)
    return 0;

    int intdex1 = (store.size()+1)/2;
    int intdex2 = (store.size()+2)/2;

    return (store[intdex1-1]+store[intdex2-1])/2.0;
    }

};