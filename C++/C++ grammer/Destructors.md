#Destructors
当一个对象跑出块范围或者显示调用`delete`，一个析构函数被自动调用，析构函数和类的名字相同，前面添加一个`~`，

如果没用定义一个析构函数，编译器会提供一个析构函数，对很多类来说，是很高效的。当类存储了系统资源需要释放或者指针指向自己的内存时，需要显示定义一个析构函数。

```c++ {.line-numbers}
// spec1_destructors.cpp
#include <string.h>

class String {
public:
   String( char *ch );  // Declare constructor
   ~String();           //  and destructor.
private:
   char    *_text;
   size_t  sizeOfText;
};

// Define the constructor.
String::String( char *ch ) {
   sizeOfText = strlen( ch ) + 1;

   // Dynamically allocate the correct amount of memory.
   _text = new char[ sizeOfText ];

   // If the allocation succeeds, copy the initialization string.
   if( _text )
      strcpy_s( _text, sizeOfText, ch );
}

// Define the destructor.
String::~String() {
   // Deallocate the memory that was previously reserved
   //  for this string.
   if (_text)
      delete[] _text;
}

int main() {
   String str("The piper in the glen...");
}

```

##声明一个析构函数

定义一个析构函数有几个规则:
>1. 不接受参数
>2. 没有返回值
>3. 不能定义为const、volatile、static.
>4. 可以声明为虚拟。 使用虚拟析构函数，您可以在不知道其类型的情况下销毁对象 - 使用虚函数机制调用对象的正确析构函数。 请注意，析构函数也可以声明为抽象类的纯虚函数。

##使用析构函数
下面事件发生将会调用析构函数：
>1. 本地对象离开作用域
>2. 调用new的操作符生成的对象调用delete
>3. 临时对象生命周期结束
>4. 程序结束，全局函数和静态函数退出
>5. 通过显示调用析构函数

关于析构函数的两个限制:
>不能取析构函数地址
>继承类无法继承父类的析构函数


##析构函数顺序
>1.调用类的析构函数，并执行析构函数的主体。
>2.非静态成员对象的析构函数以它们出现在类声明中的相反顺序调用。 用于构造这些成员的可选成员初始化列表不会影响构造或销毁的顺序。
>3.非虚拟基类的析构函数以声明的相反顺序调用。
>4. 虚拟基类的析构函数以与声明相反的顺序调用。


##虚继承
```c++ {.line-numbers}

class A
class B
class C : virtual public A, virtual public B
class D : virtual public A, virtual public B
class E : public C, public D, virtual public B
```

