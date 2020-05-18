#include <stdio.h>
#include <stdlib.h>
int a[200],b[200];
double FindOneMiddle(int a[],int left,int right)
//�ҵ���������λ��
{
    double mid;
    int n=right-left+1;
    //��n��Ԫ��
    if(n%2==0)//��ż����Ԫ��
        mid=(a[n/2]+a[n/2-1])*1.0/2;
              //��������Ԫ��
    else
        mid=a[n/2]*1.0;
    return mid;
}
int max(int a,int b)
{
    if(a>=b) return a;
    else return b;
}
int min(int a,int b)
{
    if(a>=b) return b;
    else return a;
}
double FindMiddle(int a[],int aleft,int aright,int b[],int bleft,int bright)
{
     double result,mida,midb;
     if(aright-aleft==0)
        return (a[aleft]+b[bleft])*1.0/2;//һ��Ԫ�� ֱ�ӷ���
     //�ҵ�a b������λ��
     mida=FindOneMiddle(a,aleft,aright);
     midb=FindOneMiddle(b,bleft,bright);
     //ֻ������Ԫ��
     if((aright-aleft)==1&&(bright-bleft)==1)
     {
         return (max(a[aleft],b[bleft])+min(a[aright],b[bright]))*1.0/2;
     }
     if(mida==midb)
     {
         return mida*1.0;
     }// ����������λ����ͬ ��ô�����λ��������ǰ������λ��
     //�������� ż��������
     else if(mida>midb)//a��벿��  b�Ұ벿��
     {
        if((aright-aleft+1)%2==0)
        {
         result=FindMiddle(a,aleft,(aright-aleft)/2,b,(bleft+bright)/2+1,bright);
        }
        else
        {
         result=FindMiddle(a,aleft,(aright-aleft)/2-1,b,(bleft+bright)/2+1,bright);
        }
     }
     else if(mida<midb)//a�Ұ벿�� b��벿��
     {
         if((aright-aleft+1)%2==0)
         {
         result=FindMiddle(a,(aleft+aright)/2+1,aright,b,bleft,(bright-bleft)/2);
         }
         else
         {
             result=FindMiddle(a,(aleft+aright)/2+1,aright,b,bleft,(bright-bleft)/2-1);
         }
     }
     return result;
}
int main()
{
    FILE *In,*Ou;
    int n;
    if((In=fopen("D:\\input.txt","r"))!=NULL)
    {
        fscanf(In,"%d",&n);
        int i;
        for(i=0;i<n;i++)
        {
            fscanf(In,"%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            fscanf(In,"%d",&b[i]);
        }
        fclose(In);
    }
    else
        printf("�����ļ���ʧ�ܣ�\n");
    double result=FindMiddle(a,0,n-1,b,0,n-1);
    if((Ou=fopen("D:\\output.txt","w"))!=NULL)
    {
        fprintf(Ou,"%.1lf",result);
        fclose(Ou);
    }
    else
        printf("����ļ���ʧ�ܣ�\n");
    return 0;
}
