class MyClass
{
public:
	//MyClass() { x = 0; y = 0; }
	MyClass(int a = 0, int b = 0);
	//每个函数运行时都需要一个返回值类型 并且返回值类型必须在声名该函数时指定
	//故设置Print函数为void型
	void Print();
	//int &get_x() { return x; }
	//int &get_y() { return y; }
	int x, y;
};
#pragma once
