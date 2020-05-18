M#include<iostream>   
using namespace std;
#include"MyClass.h"
//不能重新定义默认参数 如果需要参数的其他值 则应将默认参数留空
//为什么呢
MyClass::MyClass(int a, int b)
{
	x = a;
	y = b;
}
void MyClass::Print()
{
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}