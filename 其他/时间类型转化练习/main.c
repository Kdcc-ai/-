#include <stdio.h>
#include <stdlib.h>
#include "time.h"
int main()
{
    time_t t;
    t=time(NULL);//获取从1970年1月1日到现在的秒数
    printf("%ld\n",t);//转化我实际日期时间的表示格式
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

    //还可以通过年月日小时分钟秒获得time_t类型数据
    return 0;
}
