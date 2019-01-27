
#include <map>
#include <vector>

using namespace std;

class Solution
{

    map<char,int> Qstore;
    string s;
public:

    void Insert(char ch)
    {
         s +=ch;
         Qstore[ch]++;
    }

    char FirstAppearingOnce()
    {
        for(int i = 0;i < s.size();i++)
        if(Qstore[s[i]] == 1)
        return s[i];

        return '#';
    }

};