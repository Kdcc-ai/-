#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    //n����
    int bound,exchange=n-1;
    //exchange�����ж��Ƿ�����˽���
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int bound,exchange=n-1;
    while(exchange!=0)
    {   bound=exchange;
        exchange=0;
        int j=0;
        for(j=0;j<bound;j++)
        {
            if(a[j]>a[j+1])
            {
                //����

                exchange=j;//��¼����Ǵν�����λ�� �´ν��������
            }
        }
    }//�������˼· �������� ������������Ϣ����
    return 0;
}
