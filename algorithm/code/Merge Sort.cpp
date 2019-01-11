#include <iostream>

using namespace std;


void merge(int a[],int l,int m,int r){
    int count1 = m-l+1;
    int count2 = r-m;

    int tmp_a[count1];
    int tmp_b[count2];

    int i=0 ,j  =0;
    while(i < count1){
        tmp_a[i] = a[l+i];
        i++;
    }
    

    while(j < count2){
        tmp_b[j] = a[m+1+j];
        j++;
    }
    

    i = 0;
    j = 0;
    int k = 0;
    while(i < count1 && j < count2){
        if(tmp_a[i] < tmp_b[j]){
            a[l+k] = tmp_a[i];
            i++;
        }else{
            a[l+k] = tmp_b[j];
            j++;
        }
        k++;
    }

    while(i < count1){
        a[l+k] = tmp_a[i];
        k++;
        i++;
    }

    while(j < count2){
        a[l+k] = tmp_b[j];
            j++;
            k++;
    }
}

void mergesort(int a[],int l, int h){
    if(l < h){
        int m = l + (h-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,h);
        merge(a,l,m,h);
    }
}

void pri(int a[],int size){
    for(int i = 0;i < size;i++){
        cout<<a[i]<<" ";
    }

    cout<<endl;
}

int main(){
    int a[] = {1,3,4,2,5,2,5,7};
    pri(a,sizeof(a)/sizeof(int));
    mergesort(a,0,sizeof(a)/sizeof(int)-1);

    pri(a,sizeof(a)/sizeof(int));
}