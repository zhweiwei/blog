#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> str;
        for(auto val:numbers)
        str.push_back(to_string(val));

        sort(str.begin(),str.end(),Cmp);

        string s{};
        for(auto val:str)
        s += val;

        return s;

    }

    static bool Cmp(const string &p, const string &q){
        string s1=p+q;
        string s2=q+p;

        return s1 < s2;
    }
};