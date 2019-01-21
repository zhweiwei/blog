#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
         vector<int> reval;
         if(k  <= 0 || input.size()< k)
         return reval;

        for(int i = 0;i < k;i++){
            reval.push_back(input[i]);
        }

        make_heap(reval);

        for(int i = k;i < input.size();i++){
   
            if(input[i] < reval[0]){
                reval[0] = input[i];
                
                modifystack(reval,0,k);
            }
        }
 //       qsort(reval.begin(), reval.end());
        return reval;
    }

    void make_heap(vector<int> &st){
            for(int i = st.size()/2;i >= 0;i--){
                modifystack(st,i,st.size());
            }
        }
 
    
    void modifystack(vector<int> &st,int pos,int size){
        int k = pos;
        if(2 * pos < size && st[2*pos]> st[k])
        k =2* pos;

        if(2* pos+ 1< size && st[2*pos +1]> st[k])
        k = 2*pos +1;

        if(k != pos){
            int tmp = st[pos];
            st[pos] = st[k];
            st[k] = tmp;
            modifystack(st,k,size);
        }
    }

};

int main(){
    vector<int> ve ={4,5,1,6,2,7,3,8};
    Solution s;
    vector<int> m = s.GetLeastNumbers_Solution(ve,4);
/*
    for(int i = 0;i < m.size();i++){

        cout << m[i] <<" ";
    }
*/
    vector<int> h = m;
    for(int i = 0;i < h.size();i++){
        cout << h[i] <<" ";
    }
}