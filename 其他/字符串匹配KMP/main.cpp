#include <iostream>

using namespace std;
//KMP�㷨
//��һ�ι����� �Ѿ�get���������Ĳ�������(ͨ���Ӵ�)
//����get������Щ���������Լ��Ӵ���ĳЩ����(next[]��������洢)
//���Ӵ��������Ƽ�λ

//��next[j]��ʾ��һ��j��λ�ĵط�
//��ʵnext[j]���ǵ�j��Ԫ��ǰj-1��Ԫ����β�غϵĲ��ָ�����1(�����β�غϲ��ֵĸ���Ӧ��ȡ����� ��next[j]Ӧȡ�������ֵ)
//���next����
void Getnext(char ch[],int clen,int next[])
{
   next[1]=0;
   int i=1,j=0;
   while(i<=clen)
   {
       if(i<=clen)
       {
           if(j==0||ch[i]==ch[j] next[++i]=++j;
           else j=next[j];
       }
   }
}
