#include <vector>
#include <iostream>
#include <cstddef>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> tmp;
        if(str.size() == 0)
            return tmp;
        
        Permutation(tmp,str,0);

        sort(tmp.begin(),tmp.end(),less<string>());
        return tmp;
    }

    void Permutation(vector<string> & st,string str,int pos){


        if(str[pos] == '\0'){
            st.push_back(str);
            return;
        }

        for(int i = pos;i < str.size();i++){
            if(i != pos && str[pos] == str[i])
            continue;
            
            char tmp = str[pos];
            str[pos] = str[i];
            str[i] = tmp;
            Permutation(st,str,pos+1);

            tmp = str[i];
            str[i] = str[pos];
            str[pos] = tmp;
        }
    }
};