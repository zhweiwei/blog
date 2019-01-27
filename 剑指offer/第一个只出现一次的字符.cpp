#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.size() == 0)
        return -1;

        map<char,int> mapval;

        for(int i = 0;i < str.size();i++){
            ++mapval[str[i]];
        }

        for(int i = 0;i < str.size();i++)
        if(mapval[str[i]] == 1)
        return i;

        return -1;
    }
};