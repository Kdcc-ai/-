#include <stdio.h>
#include <stdlib.h>
int m[101][101];//ǰi������ �ֳ�j��
int a[101];//�������
int cal(int a[],int i,int j)
{
    int value=0;
    while(j>=i)
    {
        value=value*10+a[i];
        i++;
    }
    return value;
}
int main()
{
    FILE *In,*Ou;
    int n,k,i,j;
    int num;
    int max,value;
    if((In=fopen("D:\\input.txt","r"))!=NULL)
    {
        fscanf(In,"%d %d",&n,&k);
        fscanf(In,"%d",&num);
        int i=n;
        while(num)
        {
            a[i]=num%10;i--;
            num/=10;
        }
        fclose(In);
    }
    else
    {
        printf("�����ļ���ʧ�ܣ�\n");
    }
    if(k>=n)
    {
        printf("����λ�����ڵ�������λ�� ���벻�Ϸ�\n");
        return 0;
    }
    /*
    m[i][j]��ʾǰi�����ֳ�j�ε����˻�
    ����������ԭ�� �ص�������
    ��̬�滮����
    */
    m[1][1]=a[1];
    for(i=2;i<=n;i++)
        m[i][1]=m[i-1][1]*10+a[i];
    for(i=2;i<=k;i++){//�ֳɶ��ٶ� ͳ�Ƶ�k�μ���
        max=-1;
        for(j=i;j<=n;j++){//ͳ��ǰj��Ԫ�طֳ�i�ε����˻�
            int d;
            for(d=1;d<=j-1;d++){
                value=m[d][i-1]*cal(a,d+1,j);//��ǰd�����ֳ�i-1���ٳ��ϴ�d+1~j
                if(value>max)
                    max=value;
            }
            m[j][i]=max;
        }
    }
    if((Ou=fopen("D:\\output.txt","w"))!=NULL)
    {
        fprintf(Ou,"%d",max);
        fclose(Ou);
    }
    else
    {
        printf("����ļ���ʧ��\n");
    }
    return 0;
}
