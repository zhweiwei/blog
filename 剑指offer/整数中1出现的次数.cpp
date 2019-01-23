class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    int count = 0;
    if (n <= 0)
    return 0;

    for(int i = 1; i<= n;i++){
        while(i){
            if(i%10 == 0)
            count++;
            i = i/10;
        }
    }
    return count;
    }
};