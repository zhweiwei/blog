## 信号之signal
我们首先学习一个接口函数
>void (*signal(int signo,void(*func)(int)))(int)

看到这个函数，是不是被吓到了。哪有这么复杂的函数啊。我们先分析下这个函数。

令f=signal(int signo,void(*func)(int)),则上面的声明就是void(*f)(int),这个大家都知道是一个函数指针的声明。我们再看看f，f是一个函数声明。他的返回值是一个函数指针。函数指针类型为void(*)(int);如果还是不怎么理解呢，我就要放大招了。代码搞起来.

**代码**
```c
typedef void(*handler)(int);

handler signal(int,handler);

```

这个大招是不是很牛。首先handler是一个函数指针。指向参数为int返回void类型的函数，signal是一个函数，参数是一个int类型和一个函数指针参数，返回值也是函数参数指针。

signal函数设置一个信号（signo)的处理函数（func)，函数可以是SIG_IGN，SIG_DEL或者是其他自定义的函数，如果一个信号递送到一个进程中，下面的一个事件将会发生：
>1. 如果func设置为SOG_IGN（ignore），这个信号就会被忽视
>2. 如果func设置为SIG_DFL（default)，这个信号的默认程序将会执行
>3. 如何func是一个自定义的函数，之后函数通过signo作为参数进行调用，函数被调用期间，这个信号将被阻塞直到函数返回。

<font color="red">注意：SIGKILL 和SIGSTOP不被捕获或者忽略</font>

正与上面说的。signal函数的返回值也为函数指针。返回值为信号处理函数后者SIG_ERR，如果signal函数出错，就返回SIG_ERR。





