#include<iostream>  
using namespace std;
class IntArray {
public:
	IntArray(int sz);           // �����ʼ��Ϊsz��Ԫ�أ���ֵȫΪ0
	IntArray(int *array, int sz);  // �þ�̬����array��ǰsz��Ԫ�س�ʼ��������
	IntArray(const IntArray &rhs); // �������캯��
	~IntArray() { cout << "��������������" << endl; }
	void CreatSpace(int size=0);
	void printAll();
private:
	int *ia;
	int size;
};
void IntArray::CreatSpace(int size)
{
	this->size = size;
	ia = new int[size];
}
//��ʼ��sz��Ԫ��
IntArray::IntArray(int sz) {
	CreatSpace(sz);
	for (int ix = 0; ix < size; ++ix)
		ia[ix] = 0;     // ��ʼ������Ԫ��
}
//��ʼ��ǰsize��Ԫ��
IntArray::IntArray(int *array, int sz) {
	CreatSpace(sz);
	for (int ix = 0; ix < size; ++ix)
		ia[ix] = array[ix];    // �������ݳ�Ա
}
//��ʼ��ǰsize��Ԫ��
IntArray::IntArray(const IntArray &rhs)
{
	CreatSpace(rhs.size);
	for (int ix = 0; ix < size; ix++)
		ia[ix] = rhs.ia[ix];
}
void IntArray::printAll()
{
	for (int ix = 0; ix < size; ++ix)
		cout << ia[ix] << "  ";
	cout << endl;
}
int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	IntArray arr1(10), arr2(a, 5), arr3(arr2);
	arr1.printAll();
	arr2.printAll();
	arr3.printAll();
	return 0;
}