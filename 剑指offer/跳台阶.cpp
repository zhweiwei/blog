class Solution {
public:
    int jumpFloor(int number) {
        int result[] = {0,1};
        if(number<1)
            return 0;
        if(number == 1)
            return 1;
        if(number == 2)
            return 2;
        int a = 1,b = 2,c;
        for(int i = 3;i <= number;i++)
        {
            c = b + a;
            a = b;
            b = c;
        }
        return c;
    }
};