#include <stdio.h>

void sortnumber(int *arr,int n){
    int i ,j;
    int tmp;
    for(i = 0;i < n;i++){
        for(j = 0;j < n-i-1;j++){
            if(arr[j]> arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j] = tmp;
            }
        }
    }
}

int main(){
    int arr[10]; //用于存输入的十个数
    int i ;
    printf("请输入10个数：");
    for(i = 0; i < 10;i++) //依次存储十个数
    scanf("%d",&arr[i]);
    sortnumber(arr,10);
    printf("排序后的数字：");
    for(i = 0;i < n;i++)
    printf("%d  ",arr[i]);
}