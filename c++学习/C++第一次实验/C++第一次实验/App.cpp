//https://blog.csdn.net/zhaoyong26/article/details/84635383 �ǹ���include���ظ���������
//���캯����Ĭ�ϲ�����ʹ��
//ʱ�̼�ס���ܻ����������֮��Ķ���
//������ֵ
//����ȱ������˵���� - �ٶ�Ϊ int��ע��: C++ ��֧��Ĭ�� int---->���������https://blog.csdn.net/aa4790139/article/details/8235823

#include<iostream>  
#include"MyClass.h"
using namespace std;
int main()
{
	//���ֱ����obj���� �Ҹо�Ӧ���ǻ����������
	//����ʹ��obj() �����ʹ��obj() �������Ὣobj1��Ϊһ������

	//���Ը�������취��ע��obj���޲ι��캯��
	//��ʵ �޲ι��캯���������׸���
	MyClass obj1, obj2(5, 8);
	//C2659������ָ������������ߡ�
	//1.�������ѽ���������ı�ʶ������Ϊ���� ������ϣ�����Ǳ���
	//2.https://docs.microsoft.com/zh-cn/cpp/error-messages/compiler-errors-2/compiler-error-c2659?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev15.query%3FappId%3DDev15IDEF1%26l%3DZH-CN%26k%3Dk(C2659)%26rd%3Dtrue&view=vs-2019
	obj1.x = 1;
	obj1.y = 3;
	obj1.Print();
	obj2.Print();
	return 0;
}