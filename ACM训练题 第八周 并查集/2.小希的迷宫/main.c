#include <stdio.h>
#include <stdlib.h>
//
int father[100010];
int vis[100010];//���ڱ�����Ƿ��Ѿ�ͳ����
int ok;
void merge(int a,int b){//�ϲ����жϲ���
  int A,B;
  A=find(a);
  B=find(b);
  if(A!=B){
    father[B]=A;
  }
  else{
    ok=0;
      }
}


int find(int a)  {
     int r=a;
     while(father[r]!=r)
        r=father[r];
     int i=a;
     int j;
     while(i!=r)
        {
        j=father[i];
        father[i]=r;
        i=j;
        }
    return r;  }

int main()
{
    int m,n,i;
    while(~scanf("%d%d",&m,&n)){
        if(m==0&&n==0)   {
            printf("Yes\n");
            continue;//���ν��� ��ʼ��һ������
                          }

        for(i=0;i<100010;i++)
        {
            father[i]=i;
            vis[i]=0;//�Ƚ��б��,����0֤��û���������,��������߶�û��
        }

        if(m==-1&&n==-1) break;
        merge(m,n);//�Ե�һ�������m,n���кϲ�
        ok=1;
        vis[m]=1;
        vis[n]=1;//��ʾm��n�Ѿ����ʵ���
        scanf("%d %d",&m,&n);
        while(m!=0&&n!=0) {
            merge(m,n);
            vis[m]=1;
            vis[n]=1;
            scanf("%d %d",&m,&n);
                          }

        if(ok==0){
            printf("No\n");
            continue;
                 }

        else{
            int count=0;
        for(i=0;i<=100010;i++)  {
             if(vis[i]&&father[i]==i)
               count++;
                                }

             if(count==1)
               printf("Yes\n");
             else
               printf("No\n");
        }
             }
    return 0;
}
