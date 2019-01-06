#PDO类型
PDO 类型是平凡的(trivial)和标准布局的(standard layout)结合体.

##平凡的定义
1. 拥有平凡的默认构造函数和析构函数
>通常情况下，不定义类的构造函数，编译器会为我们生成一个平凡的默认够着函数，一旦定义了构造函数，即使构造函数没有任何参数，函数体没有任何代码，这个函数也是不平凡的，当然我们可以通过`=default`关键字显示声明构造函数

2. 拥有平凡的拷贝函数和移动构造函数
3. 拥有平凡的拷贝复制函数和移动复制函数符
4. 不能拥有包含虚函数以及虚继承

##标准布局
1. 所有的非静态成员用相同的访问权限
2. 没有虚函数和虚继承
3. 所有的非静态成员都是标准buju
4. 所有的基类都是标准布局
5. 继承类中第一个非静态类型不是基类的类型
6. 满足下面条件:
6.1. 基类有非静态成员，派生类没有非静态成员
6.2. 派生类有非静态成员，且只有一个仅包含静态成员的基类

```c++{.line-numbers}
//3-6-2.cpp
#include <iostream>

using namespace std;

struct B1{};
struct B2{};

struct D1:B1{
	B1 b;
	int i;
};

struct D2:B1{
	B2 b;
	int i;
};

int main(){
	D1 d1;
	D2 d2;

	cout <<hex;
	cout <<reinterpret_cast<long long>(&d1)<<endl;
	cout <<reinterpret_cast<long long>(&(d1.b))<<endl;
	cout <<reinterpret_cast<long long>(&(d1.i))<<endl;

	cout <<reinterpret_cast<long long>(&d2)<<endl;
	cout <<reinterpret_cast<long long>(&(d2.b))<<endl;
	cout <<reinterpret_cast<long long>(&(d2.i))<<endl;
	
}


```

```c++ {.line-numbers}
7ffc5d97a0c0
7ffc5d97a0c1
7ffc5d97a0c4
7ffc5d97a0b0
7ffc5d97a0b0
7ffc5d97a0b4


```