#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Smith������
int main()
{
    int N;
    scanf("%d",&N);//��������N
    while(N!=0)
                                   {
     int sum1=0;
     int t=N;
     int k=N;//k����N
        while(t!=0)
        {
            sum1+=t%10;
            t=t/10;
        }//���������λ�����֮��sum1
        int divide;
        int sum2=0;
     while(1)        {
        int flag=0;
        for(divide=2;divide<=sqrt(k);divide++)
            if(k%divide==0)
            {
                sum2+=divide;
                k=k/divide;
                flag=1;
                break;
            }
        if(flag==0)//�������� û���ٳ���
             {
                while(k!=0)
                    {
                        sum2+=k%10;
                        k=k/10;
                    }
                    break;
              }
                        }//���������ֽ�ʽ��λ��Ӻ�Ϊsum2

       if(sum1==sum2)
       {
           printf("%d\n",N);
           scanf("%d",&N);
       }
       else
       {
           N++;
       }
                                     }
    return 0;
}
