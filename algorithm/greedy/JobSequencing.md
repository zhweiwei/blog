# 作业排序问题 | 第一部分（贪心算法）
****
给定一系列的工作，这些工作都有截至时间并且在截至时间之前完成将会有收益，并且每个工作只需要1个单位时间，所以最小的截至时间为1.如果一次只能安排一项工作，如何使总利润最大化。

#### 例子
输入：给出下面四个工作，每个工作都有截止时间和收益

|ID|deadline|Profit|
|-|:-:|-|
|a|4|20|
|b|1|10
|c|1|40  
|d|1|30

输出：以下是作业的最大利润序列：c,a

输入：给出下面五个工作，每个工作都有截止时间和收益

|ID|deadline|Profit|
|-|:-:|-|
|a|2|100|
|b|1|19
|c|2|27
|d|1|25
|e|3|15

输出：以下是作业的最大利润序列：c, a, e

***
一个解决的方案就是生成工作集合的所有子集，，在这些子集中检查符合要求的子集。在这些符合要求的子集中，寻找最大收益。这个时间复杂度是指数集

这是一个标准的贪心算法问题。下面是这个算法：
1. 工作序列按照收益降排序
2. 用排序好的工作序列的第一个工作来初始化结果序列
3. 对剩余的n-1个工作做下面的操作
>如果当前作业可以符合当前结果序列而不会错过最后期限，则将当前作业添加到结果中。否则忽略当前作业。

**算法代码**
```c
#include <iostream>
#include <algorithm>
using namespace std;

//结构体
struct Job
{
    char id;
    int dead;
    int profit;
};

//比较函数
bool comparison(Job a,Job b)
{
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[],int n)
{
    sort(arr,arr+n,comparison);//排序

    int result[n];//保存结果
    bool slot[n];//追踪空闲时间

    for(int i = 0;i < n;i++)
	slot[i] = false;//初始化空闲时间

    for(int i = 0;i < n;i++)
    {
	for(int j = min(n,arr[i].dead) -1;j>= 0;j--)
	{
	    if(slot[j] == false)
	    {
		result[j] = i;
		slot[j] = true;
		break;
	    }
	}
    }

    for(int i = 0;i < n;i++)
	if(slot[i])
	    cout <<arr[result[i]].id<<" ";
    cout <<endl;
}

int main() 
{ 
        Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	 cout << "Following is maximum profit sequence of jobsn"; 
	printJobScheduling(arr, n); 
	return 0; 
}
```
**输出**
>Following is maximum profit sequence of jobsn: c a e

***
## 时间复杂度
上面的时间复杂度为 O(n^2),下一节我将介绍一个更快的算法：

