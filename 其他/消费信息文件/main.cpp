#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define UNIT 15 //��С�շѵ�Ԫ15����
#define CHARGE 0.5 //ÿ���շѵ�Ԫ�շ�0.5Ԫ
typedef struct Billing
{
    char aCardName[18];//����
    time_t tStart;//�ϻ�ʱ��
    time_t tEnd;//�»�ʱ��
    float Amount;//���ѽ��
    float fBalance;//���

    struct Billing *next;
}Billing;
Billing *initial2()
    {
        Billing *Info;
	    Info= (Billing*)malloc(sizeof(Billing));
	    Info->next = NULL;
        return Info;
    }

Billing *readInfo()
{
      Billing *Info=initial2();
      FILE *file;
      file = fopen("D:\\�Ʒѹ���ϵͳ3\\�Ʒѹ���ϵͳ4\\billing.ams", "ab");
	  fclose(file);

      Billing *bill;
      bill=(Billing*)malloc(sizeof(Billing));
       if((file=fopen("D:\\�Ʒѹ���ϵͳ3\\�Ʒѹ���ϵͳ4\\billing.ams","rb"))!=NULL)
       {
         while(!feof(file))
             fread(bill,sizeof(struct Billing),1,file);
        printf("%.1f",bill->Amount);
        Info->next=bill->next;
        Info->next=bill;
       }
       else
       {
         printf("�ļ���ȡʧ��");
       }
       fclose(file);

       return Info;

}
int main()
{
    Billing *Info=readInfo();

    return 0;
}
