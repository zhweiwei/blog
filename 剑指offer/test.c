
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100

int main(){
    int count;
    printf("请输入红包金额：");
    scanf("%d",&count);

    int n;
  //  n = rand()%((int)sqrt(count)) +1; //随机生成红包个数，这个算法可以自己想一个
    n = rand()%(count) +1;
    int i;
    double a[N] = {0}; //初始化为0
    for(i = 0;i < n-1;i++){
        a[i] = rand()%(count*100)/100.0;
        count -=a[i];  //剩余红包金额
        if(count == 0)
        break;
    }
    a[i] = count;

    printf("生成的红包数量%d:分别为:",n);
    for(i = 0;i < n;i++)
    printf("%.2lf ",a[i]);
    
}