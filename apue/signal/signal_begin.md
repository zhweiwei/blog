## 信号初识

首先，我们先来行代码，见识下信号的威力；

**代码**

```c
//meetsignal.cc 
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define ERR(msg) do{perror(msg);exit(0);}while(0)


int main()
{
    if(signal(SIGINT,SIG_IGN) == SIG_ERR)
	ERR("signal error");

    pause();
}


```

编译完后执行，当我们按CTRL+C时，发现程序没有什么反应，这就奇怪了。书上都说CTRL+C是将前端进程杀死的。到了我们这个程序，怎么就失效了。是不是很好奇。这就是信号的力量。控制程序正常执行。

下面我将介绍几个我们后面将使用到的信号；

|信号|含义|
|-|:-----:|
|SIGINT |程序终止(interrupt)信号, 在用户键入INTR字符(通常是Ctrl-C)时发出 
|SIGQUIT| 和SIGINT类似, 但由QUIT字符(通常是Ctrl-)来控制. 进程在因收到
|SIGUSR1| 用户定义信号1
|SIGUSR2 |用户定义信号2
|SIGALARM |时钟定时信号, 计算的是实际的时间或时钟时间. alarm函数使用该信号.
|SIGCHLD |子进程结束时, 父进程会收到这个信号
|SIGTSTP | 停止进程的运行, 但该信号可以被处理和忽略.Ctrl-Z发出这个信号
|SIGABRT | 程序自己发现错误并调用abort时产生. 

接下来，我们将详细的介绍信号方面的知识。