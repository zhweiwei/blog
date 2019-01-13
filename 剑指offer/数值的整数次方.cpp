using namespace std;
class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent == 0)
        return 1;
        double result = 1;
        if(exponent < 0){
            exponent = 0-exponent;
            base = 1/base;
        }
            
        for(int i = 1; i <= exponent;i++){
            result *=base;
        }

        return result;
    }
};