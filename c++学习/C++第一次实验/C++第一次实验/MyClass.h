class MyClass
{
public:
	//MyClass() { x = 0; y = 0; }
	MyClass(int a = 0, int b = 0);
	//ÿ����������ʱ����Ҫһ������ֵ���� ���ҷ���ֵ���ͱ����������ú���ʱָ��
	//������Print����Ϊvoid��
	void Print();
	//int &get_x() { return x; }
	//int &get_y() { return y; }
	int x, y;
};
#pragma once
