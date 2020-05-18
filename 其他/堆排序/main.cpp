#include <iostream>
#include<stdio.h>
#include<cstring>
#define LeftChild(i) (2*(i)+1)
using namespace std;
//一、
//好处:空间O(1) 相对稳定效率都是O(nlogn)不变
//注意这里的稳定特指平均时间复杂度=最坏时间复杂度，
//              最好情况：O(1)
//不是那个“稳定”，因为堆排序本身是不稳定的）

//二、
//1.先构造大根堆[必须是完全二叉树](通过不断下沉)
//2.首尾交换,断尾重构大根堆,重复第二步
//直到断掉所有尾巴

//三、
//如果n很大,使用快速排序,归并排序,堆排序时间复杂度低的算法合适
//元素下沉方法

//四、学习博客
//讲的真好：https://www.jianshu.com/p/938789fde325
void PercDown(int A[], int i, int N)
{
    int child;
    //(注：每一个节点都可以看作是其子树的根节点)
    int tmp;
    for (tmp = A[i]; LeftChild(i)<N; i = child)
    {
        child = LeftChild(i);
        //挑选出左、右子节点中较大者
        if (child != N-1 && A[child+1]>A[child])
        {
            child++;
        }
        //比较当前父节点与较大子节点
        if (A[i]<A[child])
        {
            //交换当前父节点处的元素值与较大子节点的元素值
            tmp= A[i];
            A[i] = A[child];
            A[child] = tmp;
        }
        else
        {
            break;
        }
    }
}
void Swap(int *num1, int * num2)
{
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}
void HeapSort(int A[], int N)
{
    int i;
    //先从第一个非叶子节点进行调整
    //不断调整过程中都是只调整堆顶元素就好了
    // 建堆需要的时间：O（n)
    for (i  = N/2-1;  i>=0; i--)
    {
        PercDown(A, i, N);
    }
    //调整完成之后,会进行N-1次交换+下沉
    //每次交换都得到一个最大的 所以总共N-1次
    //时间：O(nlog(2,n))
    for ( i = N-1; i > 0; i--)
    {
        Swap(&A[0], &A[i]);
        PercDown(A, 0, i);
    }
}
int main()
{
    char a[8]={'0','1','1','1','1','1','1','1'};
    char b = 0x00;
	for (int i = 0; i < 8; i++)
	{
		b = b << 1;//左移一位
		if (a[i] == '1')
		{
			b = b | 0x01;
		}
	}
	cout<<b;
    int A[6] = {4,5,3,2,6,1};
    //N为6 A[0]-A[5]
    HeapSort(A, 6);
    return 0;
}


































