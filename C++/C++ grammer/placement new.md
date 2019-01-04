#palcement new operator in c++
placement new是一个新的new操作符，一般new操作符会依次执行下面两部：
>1. 分配内存
>2. 在分配的内存中调用构造函数

placement new 允许我们分离上面两部，在placement new中，我们可以使用之前分配好的内存,在之前分配好的内存中调用构造函数,

##new VS placement new
1. 普通new在堆中分配内存并构造对象，而使用placement new，可以在已知地址完成对象构造
2. 对于普通的new，不知道它指向的是什么地址或内存位置，而使用placement new时它所指向的地址或内存位置是已知的。
3. 普通new可以通过delete去回收内存，但是placement new没有delete操作符，但是他需要可以调用析构函数提供帮助

###语法
> new (address) (type) initializer

因为它允许在已经分配的内存上构造一个对象，所以它是优化所必需的，因为它不会一直重新分配。可能存在需要多次重新构造对象的情况，因此在这些情况下，放placement new运算符可能更有效。

```c++11 {.line-numbers}

#include<iostream> 
using namespace std; 
  
int main() 
{ 
    // buffer on stack 
    unsigned char buf[sizeof(int)*2] ; 
  
    // placement new in buf 
    int *pInt = new (buf) int(3); 
  
    int *qInt = new (buf + sizeof (int)) int(5); 
    int *pBuf = (int*)(buf+0) ; 
    int *qBuf = (int*) (buf + sizeof(int)); 
    cout << "Buff Addr             Int Addr" << endl; 
    cout << pBuf <<"             " << pInt << endl; 
    cout << qBuf <<"             " << qInt << endl; 
    cout << "------------------------------" << endl; 
    cout << "1st Int             2nd Int" << endl; 
    cout << *pBuf << "                         "
         << *qBuf << endl; 
  
    return 0; 
}

```

##delete 
delete操作符只能删除堆中创建的存储，所以当使用placement new时，delete是不能删除存储的，在使用placement new操作符分配的内存，自从内存在栈中被创建，编译器会知道删除的时间并自动回收内存，如果需要的话，可以调用析构函数显示删除：

```c++ {.line-numbers}
#include<iostream> 
#include<cstdlib> 
#include<cmath> 
using namespace std; 
  
class Complex 
{ 
private: 
    double re_, im_; 
public: 
    // Constructor 
    Complex(double re = 0, double im = 0): re_(re), im_(im) 
    { 
        cout << "Constructor : (" << re_ 
             << ", " << im_ << ")" << endl; 
    } 
  
    // Destructor 
    ~Complex() 
    { 
        cout << "Destructor : (" << re_ << ", "
             << im_ << ")" << endl; 
    } 
  
    double normal() 
    { 
        return sqrt(re_*re_ + im_*im_); 
    } 
  
    void print() 
    { 
        cout << "|" << re_ <<" +j" << im_ 
             << " | = " << normal() << endl; 
    } 
}; 
  
// Driver code 
int main() 
{ 
    // buffer on stack 
    unsigned char buf[100]; 
  
    Complex* pc = new Complex(4.2, 5.3); 
    Complex* pd = new Complex[2]; 
  
    // using placement new 
    Complex *pe = new (buf) Complex(2.6, 3.9); 
  
    // use objects 
    pc -> print(); 
    pd[0].print(); 
    pd[1].print(); 
    pe->print(); 
  
    // Release objects 
    // calls destructor and then release memory 
    delete pc; 
  
    // Calls the destructor for object pd[0] 
    // and then release memory 
    // and it does same for pd[1] 
    delete [] pd; 
  
    // No delete : Explicit call to Destructor. 
    pe->~Complex(); 
  
    return 0; 
} 

```

###output
```c++{.line-numbers}

Constructor : (4.2, 5.3)
Constructor : (0, 0)
Constructor : (0, 0)
Constructor : (2.6, 3.9)
|4.2 +j5.3 | = 6.7624
|0 +j0 | = 0
|0 +j0 | = 0
|2.6 +j3.9 | = 4.68722
Destructor : (4.2, 5.3)
Destructor : (0, 0)
Destructor : (0, 0)
Destructor : (2.6, 3.9)

```

###explanation
这里显示调用析构函数是因为在这里它不能打包在delete操作符中。
