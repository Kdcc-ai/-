#include <iostream>
//дһ�㷨
//������ֵΪelem��Ԫ���ƶ���˳����ĩβ
using namespace std;
void move(int a[],int elem,int length)
{
    int j=length-1;
    int n=length-1;
    for(int i=0;i<=n;i++)
        //ѭ�� �ҵ�һ��Ԫ��
      if(a[i]==elem)
      {
          while(a[j]==elem&&j>i)
          {
              j--;
              n--;
          }
          if(j>i)
            swap(a[i],a[j]);
      }
}
int main()
{
    int a[6]={1,2,3,2,4,5};
    move(a,2,6);
    for(int i=0;i<6;i++)
        cout<<a[i];
    return 0;
}
