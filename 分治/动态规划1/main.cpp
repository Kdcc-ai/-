#include <iostream>
//Ignatius and the Princess IV
//hdu1029
//N������NΪ������ �ҳ�����ĳ�����ִ������ڣ�N+1��/2��
//1.ֱ���������� ģ��
//2.��������
//�����˼·
//��������һ�����������ȥ��������ͬ��Ԫ��
//��ôԭ�����еĶ�Ԫ�أ����µ������л��Ƕ�Ԫ��
#include<stdio.h>
using namespace std;
int main()
{
    int n,tmp,ret=0;
    while(~scanf("%d",&n))
    {
        int cnt=0;
        while(n--)
        {
            scanf("%d",&tmp);
            //����tempֵ
            if(cnt<=0) ret=tmp;
            //�������Ϊ�������̲�
            if(tmp==ret) ++cnt;
            //������1
            else --cnt;
        }
        printf("%d\n",ret);
    }
    return 0;
}
