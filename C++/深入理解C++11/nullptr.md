#C++之nullptr
`typepef decltype(nullptr) nullptr_t`


>所有定义为nullptr_t类型的数据都是等价的，行为也是完全一致；
>nullpty_t类型数据可以隐式转换为任何指针类型
>nullptr_t类型不能转换为非指针类型，即使使用reinterpret_cast方式也不行

nullptr是一个编译期间的常量，他的名字是一个编译期间的关键字，能够为编译器所识别;

```c++
int foo()
{
	int *px = (void*)0;//error
	int *py = nullptr;	 //ok

}

```

出现上面的原因是（void*)0需要显示的转换类型，nullptr可以隐式转换类型