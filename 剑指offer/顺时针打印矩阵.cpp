#include <iostream>
#include <vector>
#include <cstddef>

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> tmp;
        if(matrix.empty())
        return tmp;

        int rowmax = matrix.size() ;
        int colmax = matrix[0].size();
        int rowmin ,colmin,tamp;
        rowmin = colmin = 0;
        for(int cout= 0; cout <matrix.size() * matrix[0].size() ;){
                //打印上横向q
                if(colmax > colmin && rowmin < rowmax){
                    tamp = colmin;
                    while(tamp < colmax){
                        tmp.push_back(matrix[rowmin][tamp]);
                        tamp++;
                        cout++;
                    }
                    rowmin++;
                }

                if(colmax > colmin && rowmin < rowmax){
                    tamp = rowmin;
                    while(tamp < rowmax){
                        tmp.push_back(matrix[tamp][colmax-1]);
                        cout++;
                        tamp++;
                    }
                    colmax --;
                }

                if(colmax > colmin && rowmin < rowmax ){
                    tamp = colmax-1;
                    while(tamp >= colmin){
                        tmp.push_back(matrix[rowmax-1][tamp]);
                        tamp--;
                        cout++;
                    }
                    rowmax--;
                }

                if(rowmax > rowmin && colmax > colmin){
                    tamp = rowmax -1;
                    while(tamp >= rowmin){
                        tmp.push_back(matrix[tamp][colmin]);
                        tamp--;
                        cout++;
                    }
                    colmin++;
                }
        }
        return tmp;
    }

    
};

int main(){
    vector<vector<int> > a = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Solution s;
    s.printMatrix(a);
}