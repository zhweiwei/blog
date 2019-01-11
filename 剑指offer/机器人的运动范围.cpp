class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        int a[rows * cols];
        for(int i = 0;i < rows;i++){
            for(int j = 0; j <cols;j++){
                a[i*cols + j] = 0;
            }
        }
        int count = 0;
        runpath(threshold, rows, cols, 0 , 0, a, count);
         return count;
    }

    bool test(int m,int i ,int j){
        int tmp = 0,sum = 0;
        while(tmp = i%10){
            sum  += tmp;
            i = i/10;
        }

        while(tmp = j%10){
            sum  +=tmp;
            j = j/10;
        }

        return (sum  <= m);
    }

    void runpath(int threshold,int rows,int cols,int i ,int j,int *a,int & count){
        if(i >= 0 && i < rows && j >= 0 && j < cols&& (a[i*cols + j] == 0)&& test(threshold,i,j)){
            count +=1;
            a[i*cols + j] == 1;
            runpath(threshold, rows, cols, i+1 , j, a, count);
            runpath(threshold, rows, cols, i -1 , j, a, count);
            runpath(threshold, rows, cols, i , j +1, a, count);
            runpath(threshold, rows, cols, i , j -1, a, count);
        }
    }
};


int main(){
    Solution s;
}