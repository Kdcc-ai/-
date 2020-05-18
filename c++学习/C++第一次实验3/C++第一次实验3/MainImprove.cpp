#include<iostream>  
using namespace std;
class IntArray {
public:
	IntArray(int sz);           // 数组初始化为sz个元素，初值全为0
	IntArray(int *array, int sz);  // 用静态数组array的前sz个元素初始化新数组
	IntArray(const IntArray &rhs); // 拷贝构造函数
	~IntArray() { cout << "析构函数被调用" << endl; }
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
//初始化sz个元素
IntArray::IntArray(int sz) {
	CreatSpace(sz);
	for (int ix = 0; ix < size; ++ix)
		ia[ix] = 0;     // 初始化数组元素
}
//初始化前size个元素
IntArray::IntArray(int *array, int sz) {
	CreatSpace(sz);
	for (int ix = 0; ix < size; ++ix)
		ia[ix] = array[ix];    // 拷贝数据成员
}
//初始化前size个元素
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