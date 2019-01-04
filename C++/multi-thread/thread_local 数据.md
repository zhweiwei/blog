<script src="https://gist.github.com/nisrulz/11c0d63428b108f10c83.js"></script>
#thread_local 数据
通过关键字`thread_local`可以定义一个线程本地数据，接下来我将介绍`thread_local`

当线程本地数据需要创建时，`thread_local`数据专门属于线程,并且他的行为有点像static数据，这意味着，他第一次被创建，他的生命周期和线程的时间相同，一般的，线程本地数据通常叫做线程本地存储


###code

```c++   
// threadLocal.cpp

#include <iostream>
#include <string>
#include <mutex>
#include <thread>

std::mutex coutMutex;

thread_local std::string s("hello from ");

void addThreadLocal(std::string const& s2){

  s+=s2;
  // protect std::cout
  std::lock_guard<std::mutex> guard(coutMutex);
  std::cout << s << std::endl;
  std::cout << "&s: " << &s << std::endl;
  std::cout << std::endl;

}

int main(){

  std::cout << std::endl;

  std::thread t1(addThreadLocal,"t1"); 
  std::thread t2(addThreadLocal,"t2"); 
  std::thread t3(addThreadLocal,"t3"); 
  std::thread t4(addThreadLocal,"t4"); 

  t1.join();
  t2.join();
  t3.join();
  t4.join();

}

```

###output
```c++

hello from t2
&s: 0x7f2554d746f0

hello from t3
&s: 0x7f25545736f0

hello from t4
&s: 0x7f2553d726f0

hello from t1
&s: 0x7f25555756f0


```

