class Solution {
public:
    int jumpFloorII(int number) {
            if (number <= 0)
            return 0;

            return 1<<(number-1);
    }
};