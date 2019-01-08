#include <cstring>
#include <iostream>

class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == nullptr)
        return;

        int count,sr=0;
        count = 0;
        char *tm = str;
        while(*tm != '0'){
            sr++;
            if(*tm == ' '){
                count++;
                std::cout<<*(tm+1)<<"|";
            }
               
               tm++;
        }

        std::cout<<count <<std::endl;
        if(count == 0)
        return;

        if((strlen(str) + 2*count) > length)
        return;

        char *p,*q;

        p = str + strlen(str);
        q = p + count*2;
        
        char tmp;
        while(p != str){
            if(*p != ' '){
                *q-- = *p--;
            }else{
                *q-- = '0';
                *q-- = '2';
                *q-- = '%';
                p--;
            }
        }
        
	}
};

int main(){
    char a[100] = "dfsdb fbs fb fbs";
    Solution s;
    std::cout<< a<<std::endl;

    s.replaceSpace(a,100);
    std::cout<< a<<std::endl;
}