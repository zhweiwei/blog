
/**
 * @description: 
 * @param {type} 
 * @return: 
 * 
 */
#include <stdio.h>
#include <math.h>

#define N 100

int main(){
    int n, sum;
    
    float ave,e,s;

    printf("请输入样本数量 n：");
    scanf("%d",&n);

    printf("请输入%d 个样本",n);

    sum = 0;
    int i = 0;
    int a[N];  //用于存储数据
    for(i = 0;i < n;i++){
        scanf("%d",&a[i]);
        sum += a[i];
    }

    ave = (sum*1.0)/n;
 
    for(i = 0;i < n;i++)  
    e+= (a[i] - ave)*(a[i] - ave);

    e /=n-1;

    s = sqrt(e);  //计算标准差

    printf("平均数是 %.2f,方差是 %.2f，标准差是 %.2f\n",ave,e,s);
}

/**
 * @description: 
 * @param {type} 
 * @return: 
 */

#include <stdio.h>

double computer(double m,int da,double c){
    double day;
     day = c/(m * da);  //日利率=利息/（本金X存期）
     return day*360 ; //返回年利率
}

int main(){
    int days;
    double m,a;
    printf("请输入本金、天数、收益额:");
    scanf("%lf %d %lf",&m,&days,&a);
    double s = computer(m,days,a);
    printf("全年利息率为%f\%",s*100);
}

/**
 * @description: 
 * @param {type} 
 * @return: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100

int main(){
    int count;
    printf("请输入红包金额：");
    scanf("%d",&count);

    int n;
    n = rand()%((int)sqrt(count)) +1; //随机生成红包个数，这个算法可以自己想一个

    int i;
    int a[N] = {0}; //初始化为0
    for(i = 0;i < n-1;i++){
        a[i] = rand()%count;
        count -=a[i];  //剩余红包金额
        if(count == 0)
        break;
    }
    a[i] = count;

    printf("生成的红包数量%d:分别为:",n);
    for(i = 0;i < n;i++)
    printf("%d ",a[i]);
    
}