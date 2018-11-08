## 等你waitpid

上一章节，我们遗留了两个问题没有解决。在着章节中，我们将解决那两个问题，首先看看waitpid的的声明。
>pid_t waitpid(pid_t pid,int *statloc,int options);

对于pid有下面四种选项
>pid==-1 等待任意子进程
pid>0 等待进程ID与pid相等的子进程
pid==0 等待组ID等于调用进程组ID的任意子进程
pid<-1 等待组ID等于pid绝对值的任意子进程

当pid设置为-1时，waitpid就会和wait相同，下面一个程序是等待特定的子进程退出。

**代码**

```c
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#define ERR(msg) do{perror(msg);exit(0);}while(0)
int main()
{
    int status;
    pid_t pid1,pid2;
    int i = 0;

    while(i< 2)
    {
	if (i == 0)
	{
	    pid1 = fork();
	    if(pid1 < 0)
		ERR("fork error");
	    
	    if(pid1 == 0)
	    {
		sleep(2);
		printf("child i = %d\n",i);
		exit(0);
	    } 
	}
	if(i == 1)
	{
	    pid2 = fork();

	    if(pid2 < 0)
		ERR("fork error");
	    if(pid2 == 0)
	    {
		printf("child i = %d\n",i);
		exit(0);
	    }
	}
	i++;
    }
    pid1 = waitpid(pid1,&status,0); //等待pid1
    printf("parent i = %d\n",i);
}
```

**输出**
>child i = 1
child i = 0
parent i = 2

**分析**
首先，父进程创建了两个子进程，父进程等待第一个子进程退出，然后继续执行。如果是使用wait的调用，结果将不用。

下图左边使用的是waitpid，右图是将waipid换为wait执行的结果,

![waipid](./image/gif_process_waitpid.gif)

上右图最后才打印child i =0是由于父进程执行结束后退出，子进程还在sleep。所以才会最后打印。

我们无论只执行wait还是waitpid ，当执行之后，父进程就被阻塞。有没有办法让父进程不阻塞呢，这就是waitpid还有第三个参数完成的任务，当我们设置第三个参数为WNOHANG时，父进程不阻塞。下面我只贴上代码。你们自己执行一边。看看有什么不同。

```c
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#define ERR(msg) do{perror(msg);exit(0);}while(0)
int main()
{
    int status;
    pid_t pid1,pid2;
    int i = 0;

    while(i< 2)
    {
	if (i == 0)
	{
	    pid1 = fork();
	    if(pid1 < 0)
		ERR("fork error");
	    
	    if(pid1 == 0)
	    {
		sleep(2);
		printf("child i = %d\n",i);
		exit(0);
	    } 
	}
	if(i == 1)
	{
	    pid2 = fork();

	    if(pid2 < 0)
		ERR("fork error");
	    if(pid2 == 0)
	    {
		printf("child i = %d\n",i);
		exit(0);
	    }
	}
	i++;
    }
    pid1 = waitpid(pid1,&status,WNOHANG); //等待pid1
    //pid1 = wait(&status); //等待子进程
    printf("parent i = %d\n",i);
    sleep(2);
}


```

## 总结

了解waitpid与wait不同，掌握参数的含义和用法

