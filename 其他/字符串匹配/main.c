#include <stdio.h>
#include <stdlib.h>
//�ַ���ƥ��BF�㷨
//����n �Ӵ�m
//����ƥ��ɹ�������Si��
//����i-1�˲��ɹ���ƥ�乲�Ƚ���(i-1)*m��
//��i�αȽ���m�� �����ܹ��Ƚ���i*m��

//ƽ���Ƚϴ�����i��1��n-m+1��1/(n-m-1) * (i*m)==m*(n-m+2)/2
//һ�������m<<n �����µ�ʱ�临�Ӷ�ΪO(n*m)
int main()
{
    char S[11]={'a','b','c','b','c','b','c','b','c','d','\0'};
    char T[4]={'b','c','b','\0'};
    int index=0;
    int i=0,j=0;
    while((S[i]!='\0')&&(T[j]!='\0'))
    {
        if(S[i++]==T[j++])
            {
                ;
            }
        else
        {
            index++;
            i=index;
            j=0;
        }
    }
   //if(T[j]=='\0')
      //  printf("%d",index+1);
    return 0;
}
