#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> rtmp;
        vector <pair<int,int>> topk;

        if(nums.size() == 0 || nums.size() < k)
            return rtmp;

        map<int,int> mapval;

        for(auto value:nums)
        ++mapval[value];

        if(mapval.size() < k)
        return rtmp;

        int i = 0;
        auto iter = mapval.begin();
        for(;i < k;i++){
            topk.push_back(make_pair(iter->first,iter->second));
            iter++;
        }

        makestack(topk);

        while(iter != mapval.end()){
            if(iter->second > topk[0].second){
                topk[0] = make_pair(iter->first,iter->second);
                adjastStack(topk,0);
            }
            iter++;
        }

        for(auto val:topk)
        rtmp.push_back(val.first);

        sort(rtmp.begin(),rtmp.end());
        return rtmp;
        
    }

    void makestack(vector<pair<int,int>> &st){
        for(int i = st.size()/2;i>= 0;i--)
        adjastStack(st,i);
    }

    void adjastStack(vector<pair<int,int>>&st,int pos){
        int tmp= pos;
        if(2*pos < st.size() && st[tmp].second > st[2*pos].second)
        tmp = 2*pos;

        if(2*pos +1 <st.size() && st[tmp].second > st[2*pos +1].second)
        tmp = 2* pos+1;

        if(tmp != pos){
            pair<int ,int> k = st[pos];
            st[pos] = st[tmp];
            st[tmp] = k;
            adjastStack(st,tmp);
        }
    }
};


int main(){
    vector<int> v = {1,1,1,2,2,3};
    Solution s;
    vector <int> tmp = s.topKFrequent(v,2);

    for(auto val:tmp)
    cout <<val<<" ";
}