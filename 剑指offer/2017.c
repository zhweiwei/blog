
/*
第二题
*/
#include <stdio.h>

int main(){
    int i ,j;

    for(i = 1; i <= 4;i++){ //i 表示行数
        for(j = 1;j <= 2*i -1;j++)  //每行输出的*个数为2*i -1；
        printf("*");

        printf("\n");  //输出换行符，
    }
}


/*
第三题
*/
#include <stdio.h>

void sortnumber(int *arr,int n){
    int i ,j;
    int tmp;
    for(i = 0;i < n;i++){
        for(j = 0;j < n-i-1;j++){
            if(arr[j]> arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
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

    printf("sort after：");
    for(i = 0;i < 10;i++) //输出函数
    printf("%d  ",arr[i]);
}