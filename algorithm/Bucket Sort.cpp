#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void bucketSort(float arr[],int n){
    vector<float> b[n];

    for(int i = 0;i < n;i++){
        int bi = n*arr[i];
        b[bi].push_back(arr[i]);
    }

    for(auto value:b)
    sort(value.begin(),value.end());
    int j = 0;
    for(int i = 0;i < n;i++){
        for(auto value:b[i]){
            arr[j--] = value;
        }
    }
}