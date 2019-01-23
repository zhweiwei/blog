#include <iostream>

using namespace std;
class Solution{
  int getMax(int arr[],int n){
      if(n <= 0)
      return 0;

      int mx = arr[0];
      for(auto value:arr){
          if(mx < value)
          mx = value;
      }

      return mx;
    }

    void countSort(int arr[],int n,int exp){
        int output[n];

        int count[10] = {0};

        for(auto value:arr){
            count[(value/exp)%10]++;
        }

        for(int i = 1;i < 10;i++){
            count[i] +=count[i-1];
        }

        for(int i = n -1;i >= 0;i--){
            output[count[(arr[i]/exp)%10] -1 ] = arr[i];
            count[(arr[i]/exp)%10]--;
        }

        for(int i = 0;i < n;i++)
        arr[i] = output[i];
    }  
}
