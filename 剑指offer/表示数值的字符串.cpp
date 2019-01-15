#include <iostream>

using namespace std;
class Solution {
public:

    bool isnumb;
    bool isNumeric(char* string)
    {
        if(string == nullptr)
        return false;

        isnumb = isNum(&string);

        if(*string == '.'){
            string++;
            isnumb = isUInterger(&string) || isnumb;
        }
        

        if(*string == 'E' || *string == 'e'){
            string++;
            isnumb = isNum(&string) && isnumb;
        }

        return isnumb && *string == '\0';
    }

    bool isUInterger( char ** string){
        const char* tmp = *string;
        while(**string >= '0' && **string <= '9')
                ++(*string);
        return tmp != *string;        
    }

    bool isNum( char** string){
        if(**string == '-' || **string == '+')
        ++(*string);
        return isUInterger(string);
    }
};

int main(){
    Solution s;
    cout << s.isNumeric("123.45e+6");
}