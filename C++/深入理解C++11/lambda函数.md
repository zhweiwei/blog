#C++之lambda函数

```c++
int main()
{
	int girls = 3,boys = 4;
	auto totalChild = [](int x,int y)->int{return x + y};
	return totalChild(girls,boys);
}

```

lambda函数的语法定义
>[capture]\(parameters)mutable->return_type{statement}

[capture]的表现形式有:
>[var]表达值传递方式捕捉变量var
>[=]表示值传递方式捕捉父作用域的变量（include this)
>[&var]表示引用传递捕捉变量var
>[&]表示引用传递捕捉所有父作用域的变量
>[this]表示值传递方式捕捉当前的this指针

(parameters)的形式
与普通函数的参数列表一致，如果不需要参数传递，则连同括号（）一起省略


##局部函数
local function 也称为nested function,local function 也仅仅属兔父作用域，能够访问父作用域的变量，且在父作用域中使用。

##lambda闭包函数
使用lambda函数的时候，捕捉列表不同会导致不同的结果，按值方式传递捕捉列表和按引用方式捕捉方式列表效果是不一样的，对于按值传递的捕捉列表，其传递的值再lambda函数定义的时候已经决定了，而按引用传递的捕捉列表变量，其传递的值则等于lambda函数调用时的值，

##example
```c++
#include <iostream>
using namespace std;

int main()
{
	int j = 12;
	auto by_val_lambda = [=]{return j+1;};
	auto by_ref_lambda = [&]{return j+1;};
	cout << "by_val_lambda: "<<by_val_lambda() << endl;
	cout<<" by_ref_lambda: "<<by_ref_lambda()<< endl;

	j++;
	cout<< "by_val_lambda: "<<by_val_lambda() <<endl;
	cout<< "by_ref_lambda: "<<by_ref_lambda() << endl;
}
```

##output
>by_val_lambda: 13
 by_ref_lambda: 13
by_val_lambda: 13
by_ref_lambda: 14

##lambda函数的转换
lambda可以认为时一种自定义类型，lambda的类型并非简单的函数指针类型或者自定义类型；在lambda表达式中，会产生一个闭包的临时对象（右值）lambda函数并非函数指针，在C++11中，