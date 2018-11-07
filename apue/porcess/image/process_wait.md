## 初识wait函数

前两节我们父进程都是调用sleep函数使自己睡眠，等待子进程完成退出。由于我们不知道子进程如何执行结束。好在系统提供了函数，让父进程等待子进程结束。

当父进程调用wait函数时，可能会发生下面现象：
>1、如果其所有子进程都还在运行，则阻塞；
2、如果一个子进程已终止，正等待父进程获取其终止状态，则取得该子进程的终止状态立即返回；
3、如果没有任何子进程，则立即终止返回。

现在我们有了wait函数后，之前的程序就不需要调用sleep函数去等待子进程了，我们只需要调用wait就可以了，将之前的代码sleep函数用wait替换。
**代码**

```c
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define ERR(msg) do{perror(msg);exit(0);}while(0)
int main()
{
    pid_t pid;
    int status; //存储子进程退出状态码    
    pid  = fork();
    if(pid < 0)
	ERR("fork error");
    
    if(pid == 0)//子进程
    {
	printf("I'm child     ");//未加换行符，防止刷新缓冲区	
	exit(0);
    }
    if (pid > 0)
    {
	pid = wait(&status);
	printf("I'm parent ");
    }
}

```

执行结果和之前相同，

## 思考
>1. 由于父进程调用wait之后就需要阻塞，有什么办法不需要阻塞呢
>2. 父进程有多个进程，需要指定监听特定的子进程

下节将解决这个问题

## 总结

掌握wait的含义