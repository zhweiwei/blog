#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        int arr[rows * cols];
        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++){
                arr[i*cols+j] = 0;
                }
            }
       

        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++){
                if(findpath(matrix,  rows, cols, i, j,  str,arr)){
                    return true;
                }
            }
        }
        return false;
    }

     bool findpath(char* matrix,  int rows, int cols,int i, int j, char* str,int *arr)
     {
            if(*str == '\0')
            return true;

            if(i>=0 && i < rows && j >= 0 && j < cols && matrix[i*cols+j] == *str&&arr[i*cols+j]== 0){
            arr[i*cols+j] = 1;
            bool tmp = findpath(matrix,rows,cols,i+1,j,str+1,arr) || findpath(matrix,rows,cols,i-1,j,str+1,arr) ||findpath(matrix,rows,cols,i,j+1,str+1,arr) || findpath(matrix,rows,cols,i,j-1,str+1,arr);
            if(tmp)
             return true; 
             arr[i*cols+j] = 0;
             }         
            return false;
    }
};

int main(){
    Solution s;
    cout<<s.hasPath("ABCESFCSADEE",3,4,"ABCCED")<<endl;
}