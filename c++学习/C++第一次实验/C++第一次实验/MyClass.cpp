M#include<iostream>   
using namespace std;
#include"MyClass.h"
//�������¶���Ĭ�ϲ��� �����Ҫ����������ֵ ��Ӧ��Ĭ�ϲ�������
//Ϊʲô��
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