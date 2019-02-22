#include <stdio.h>
#include <stdlib.h>

int test(int *arr,int count, int num){ //用于检测生成的随机数之前是否已经生成过
    int i = 0;

    for(;i <count;i++){
        if(arr[i] == num)
        return -1;
    }

    return count;
}

int main(){
    int arr[5] ; //存储抽奖结果
    int i = 0;
    while(i < 5){
        int num = rand()%100 +1; //随机生成1-100的数
        int re = test(arr,i,num);
        if(re != -1){
            arr[i] = num;
            i++;
        }
    }

    printf("生成的随机数是：");

    for(i = 0;i < 5;i++){
        printf("%d ",arr[i]);
    }
}