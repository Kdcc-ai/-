#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[11],i,j,t;
    for(i=0;i<=10;i++)
        a[i]=0;
    for(i=1;i<=5;i++)
    {
        scanf("%d",&t);
        a[t]++;
    }
    for(i=0;i<=10;i++)  //�����ж�a[0]~a[10]
            for(j=1;j<=a[i];j++)  //�����˼��ξʹ�ӡ����
                printf("%d ",i);
                getchar();
                getchar();
//�Ӵ�С �򵥸Ľ�����

 //������Ͱ����

    return 0;
}
