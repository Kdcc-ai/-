#include<iostream>
#include<iomanip>
#include"cTrangle.h"
using namespace std;
int main()
{
	cTrangle C1(20, 50), C2(3.6, 4.5);
	cout << "����1��������ܳ��ֱ�Ϊ" << endl;
	cout <<fixed<<setprecision(2)<<C1.CaculateArea() <<" "<< C1.CaculateCir()<< endl;
	cout << "����2��������ܳ��ֱ�Ϊ" << endl;
	cout << fixed<<setprecision(2)<< C2.CaculateArea() << " " << C2.CaculateCir() << endl;
}