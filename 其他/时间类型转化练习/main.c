#include <stdio.h>
#include <stdlib.h>
#include "time.h"
int main()
{
    time_t t;
    t=time(NULL);//��ȡ��1970��1��1�յ����ڵ�����
    printf("%ld\n",t);//ת����ʵ������ʱ��ı�ʾ��ʽ
    struct tm *tm1,*tm2;
    tm1=gmtime(&t);

    printf("%d\n",1900+tm1->tm_year);
    printf("%d\n",1+tm1->tm_mon);
    printf("%d\n",tm1->tm_mday);

    printf("%d\n",8+tm1->tm_hour);
    printf("%d\n",tm1->tm_min);
    printf("%d\n",tm1->tm_sec);

    tm2=localtime(&t);
    printf("%d\n",1900+tm2->tm_year);
    printf("%d\n",1+tm1->tm_mon);
    printf("%d\n",tm1->tm_mday);

    printf("%d\n",tm1->tm_hour);
    printf("%d\n",tm1->tm_min);
    printf("%d\n",tm1->tm_sec);

    //������ͨ��������Сʱ��������time_t��������
    return 0;
}
