# 作业排序问题 | 第一部分（使用）
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

上面算法最昂贵的地方就是为工作寻找空闲的时间段。我们每次为工作遍历时间集并寻找最大的时间段给job。

**最大的时间是什么**
假设一个J1的截止时间 t =5;我们设置最大时间是空闲的并且小于截止时间，例如 4-5期间工作这个job1，现在job2的截止时间也是5，所以这个时间断为3-4，这是由于4-5时间段已经工作了job1；

**为什么要分配最大的时间（空闲）给job**

我们分配最大的时间段，因为如果我们分配小于这个可以分配的最大时间段的时间断，就会有其他job会无法满足截止时间；

**例如**
> job1的截止时间d1 = 5，收益40
> job2的截止时间d2 = 1,收益20

假设job1分配0-1时间断，现在job2就无法工作，因为我们将0-1时间段配分给job1


**使用不相交集**

所有的时间段都初始化独立的，我们首先寻找到工作的最大的截止时间。设最大的截止时间为m，我们将创建m+ 1个独立集合，如果一个job被安排在t时间段,这个job将安排在[t-1,t]，所以一个集合的中的值X代表[X-1,X]时间段，给定一个job，我们需要追踪最大的空闲的时间段。为了完成这个追踪目的，我们使用一个父数组的不交集。每个集合的根节点是最迟的空闲的时间段，对于一个job的截止时间d,如果没有空闲的时间段，则这个集合的根节点为0，下面是实现细节：

**初始化不交集**

```c
parent = new int[m+1];
//每个节点的父节点都是自己
for(int i= 0;i <=m;i++)
  parent[i] = i;
```

**寻找最大时间段**

```c
find(s)
{
    
    if (s == parent[s])
       return s;

    // 递推并压缩路径
    return parent[s] = find(parent[s]);
} 

```

**合并**

```c
union(u, v)
{
   // 更新最大时间段
   parent[v] = u;
} 

```

**如何寻找最大有用的时间段**

初始化所有的独立的时间段，所以返回的时间段是最大的，当我们安排时间段t给一个job。我们合并时间段t和t-1，这时时间t-1成为了t的父节点。这部操作我们调用union(t,t-1),这意味着所有对时间t的查找都会返回最迟并空闲时间t-1;

## 代码

```c
#include<bits/stdc++.h> 
using namespace std; 
  
// job的数据结构
struct Job 
{ 
    char id; 
    int deadLine, profit; 
}; 
  
// 不交集的数据结构
struct DisjointSet 
{ 
    int *parent; 
  
    
    DisjointSet(int n) 
    { 
        parent = new int[n+1]; 
  
        
        for (int i = 0; i <= n; i++) 
            parent[i] = i; 
    } 
  
   
    int find(int s) 
    { 

        if (s == parent[s]) 
            return s; 
        return parent[s] = find(parent[s]); 
    } 
  

    void merge(int u, int v) 
    { 

        parent[v] = u; 
    } 
}; 
  

bool cmp(Job a, Job b) 
{ 
    return (a.profit > b.profit); 
} 
  

// 查找最大截止时间
int findMaxDeadline(struct Job arr[], int n) 
{ 
    int ans = INT_MIN; 
    for (int i = 0; i < n; i++) 
        ans = max(ans, arr[i].deadLine); 
    return ans; 
} 
  
int printJobScheduling(Job arr[], int n) 
{ 

    //降序
    sort(arr, arr + n, cmp); 
  

    int maxDeadline = findMaxDeadline(arr, n); 
    DisjointSet ds(maxDeadline); 
  
    // 遍历job集
    for (int i = 0; i < n; i++) 
    { 

        int availableSlot = ds.find(arr[i].deadLine); 
  

        //存在可用的时间段
        if (availableSlot > 0) 
        { 

            ds.merge(ds.find(availableSlot - 1),  
                             availableSlot); 
  
            cout << arr[i].id << " "; 
        } 
    } 
} 
  
// Driver program to test above function 
int main() 
{ 
    Job arr[] =  { { 'a', 2, 100 }, { 'b', 1, 19 },  
                   { 'c', 2, 27 },  { 'd', 1, 25 },  
                   { 'e', 3, 15 } }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Following jobs need to be "
         << "executed for maximum profit\n"; 
    printJobScheduling(arr, n); 
    return 0; 
    return 0; 
} 

```

**输出**
>Following jobs need to be executed for maximum profit
a c e 