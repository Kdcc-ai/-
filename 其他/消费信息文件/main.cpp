#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define UNIT 15 //最小收费单元15分钟
#define CHARGE 0.5 //每个收费单元收费0.5元
typedef struct Billing
{
    char aCardName[18];//卡号
    time_t tStart;//上机时间
    time_t tEnd;//下机时间
    float Amount;//消费金额
    float fBalance;//余额

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
      file = fopen("D:\\计费管理系统3\\计费管理系统4\\billing.ams", "ab");
	  fclose(file);

      Billing *bill;
      bill=(Billing*)malloc(sizeof(Billing));
       if((file=fopen("D:\\计费管理系统3\\计费管理系统4\\billing.ams","rb"))!=NULL)
       {
         while(!feof(file))
             fread(bill,sizeof(struct Billing),1,file);
        printf("%.1f",bill->Amount);
        Info->next=bill->next;
        Info->next=bill;
       }
       else
       {
         printf("文件读取失败");
       }
       fclose(file);

       return Info;

}
int main()
{
    Billing *Info=readInfo();

    return 0;
}
