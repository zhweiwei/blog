#include <vector>
#include <string>

using namespace std;

class Solution {
        vector<vector<string>> store;
public:
    vector<vector<string>> partition(string s) {
        if(s.size() == 0)
        return store;
        vector<string> st;
        devide(s,0,s.size()-1,st);
        return store;
    }

    void devide(string s,int begin,int end,vector<string> st){
            if(begin >end){
                store.push_back(st);
                return;
            }

            for(int i = begin;i <= end;i++){
                if(test(s,begin,i)){
                    string substr = s.substr(begin,i-begin+1);
                    st.push_back(substr);
                    devide(s,i+1,end,st);
                    st.pop_back();                   
                }
            }
    }

    bool test(string s,int begin,int end){
        if(begin == end)
        return true;

        while(begin < end){
            if(s[begin] != s[end])
            return false;
            begin++;
            end--;
        }
        return true;
    }
};