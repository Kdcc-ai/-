#include <iostream>
#include<stdio.h>
#include<cstring>
#define LeftChild(i) (2*(i)+1)
using namespace std;
//һ��
//�ô�:�ռ�O(1) ����ȶ�Ч�ʶ���O(nlogn)����
//ע��������ȶ���ָƽ��ʱ�临�Ӷ�=�ʱ�临�Ӷȣ�
//              ��������O(1)
//�����Ǹ����ȶ�������Ϊ���������ǲ��ȶ��ģ�

//����
//1.�ȹ�������[��������ȫ������](ͨ�������³�)
//2.��β����,��β�ع������,�ظ��ڶ���
//ֱ���ϵ�����β��

//����
//���n�ܴ�,ʹ�ÿ�������,�鲢����,������ʱ�临�Ӷȵ͵��㷨����
//Ԫ���³�����

//�ġ�ѧϰ����
//������ã�https://www.jianshu.com/p/938789fde325
void PercDown(int A[], int i, int N)
{
    int child;
    //(ע��ÿһ���ڵ㶼���Կ������������ĸ��ڵ�)
    int tmp;
    for (tmp = A[i]; LeftChild(i)<N; i = child)
    {
        child = LeftChild(i);
        //��ѡ�������ӽڵ��нϴ���
        if (child != N-1 && A[child+1]>A[child])
        {
            child++;
        }
        //�Ƚϵ�ǰ���ڵ���ϴ��ӽڵ�
        if (A[i]<A[child])
        {
            //������ǰ���ڵ㴦��Ԫ��ֵ��ϴ��ӽڵ��Ԫ��ֵ
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
    //�ȴӵ�һ����Ҷ�ӽڵ���е���
    //���ϵ��������ж���ֻ�����Ѷ�Ԫ�ؾͺ���
    // ������Ҫ��ʱ�䣺O��n)
    for (i  = N/2-1;  i>=0; i--)
    {
        PercDown(A, i, N);
    }
    //�������֮��,�����N-1�ν���+�³�
    //ÿ�ν������õ�һ������ �����ܹ�N-1��
    //ʱ�䣺O(nlog(2,n))
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
		b = b << 1;//����һλ
		if (a[i] == '1')
		{
			b = b | 0x01;
		}
	}
	cout<<b;
    int A[6] = {4,5,3,2,6,1};
    //NΪ6 A[0]-A[5]
    HeapSort(A, 6);
    return 0;
}


































