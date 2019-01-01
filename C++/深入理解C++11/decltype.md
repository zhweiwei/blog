#C++之auto

##静态类型、动态类型与类型推导

静态类型表示每个变量使用之前必须定义，动态类型表示变量使用拿来就用的变量使用方式

RTTI的机制是为每个类型产生有一个type_info类型的数据，

decltype函数是RTTI机制函数,
decltype只接受表达式做参数，

decltype（e) 获取类型时，编译器依照四个规则:
>如果e是一个没有括号的标记表达式或者类型成员访问表达式，那么decltype(e)就是e所命名的实体类型，此外，如果e是被重载的函数，则会导致编译时错误,
>否则，假设e的类型时T，如果e是一个将亡值（xvalue)，那么decltype(e)为T&&
>否则，假设e的类型是T，如果e是一个左值，则decltype(e)为T&
>否则,假设e的类型是T，则decltype(e)为T

```c++
#include <iostream>
using namespace std;

template<typename T1,typename T2>
auto Sum(const T1 &t1,const T2 & t2) ->decltype(t1+t2){
	return t1+t2;
}

template<typename T1 ,typename T2>
auto mul(const T1 &t1,const T2 &t2)->decltype(t1*t2){
	return t1*t2;
}

int main()
{
	auto a = 2;
	auto b = 4L;
	auto pi = 3.14;

	auto c = mul(Sum(a,b),pi);
	cout<< c << endl;
}

```

这些代码尤其是主函数，看上去有点像一个动态类型语言的代码，而不像一个有着严格静态类型的C++的代码，当然，这些都要归功与类型推导帮助下的泛型编程，程序员在编程时无需关系任何时段类型选择，编译器会合理的进行推导，而简单程序的书写也由此得到了极大的简化

