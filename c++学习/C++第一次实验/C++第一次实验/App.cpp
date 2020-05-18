//https://blog.csdn.net/zhaoyong26/article/details/84635383 是关于include的重复引用问题
//构造函数中默认参数的使用
//时刻记住可能会产生二义性之类的东西
//关于左值
//关于缺少类型说明符 - 假定为 int。注意: C++ 不支持默认 int---->解决方法：https://blog.csdn.net/aa4790139/article/details/8235823

#include<iostream>  
#include"MyClass.h"
using namespace std;
int main()
{
	//这块直接用obj声明 我感觉应该是会产生二义性
	//所以使用obj() 但如果使用obj() 编译器会将obj1视为一个函数

	//所以根本解决办法是注销obj的无参构造函数
	//其实 无参构造函数本身就是赘余的
	MyClass obj1, obj2(5, 8);
	//C2659函数在指定操作符的左边。
	//1.编译器已将运算符左侧的标识符分析为函数 但我们希望他是变量
	//2.https://docs.microsoft.com/zh-cn/cpp/error-messages/compiler-errors-2/compiler-error-c2659?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev15.query%3FappId%3DDev15IDEF1%26l%3DZH-CN%26k%3Dk(C2659)%26rd%3Dtrue&view=vs-2019
	obj1.x = 1;
	obj1.y = 3;
	obj1.Print();
	obj2.Print();
	return 0;
}