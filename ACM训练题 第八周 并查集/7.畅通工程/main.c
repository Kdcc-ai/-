#include <stdio.h>
#include <stdlib.h>
typedef struct edge{
   int u;//�ߵ���ʼ����
   int v;//�ߵ���ֹ����
   int w;//�ߵ�Ȩֵ
}edge;
edge E[4950]={0};
//�ṹ�嶨��
int find_father(int father[],int n){
    int r=n;
    while(father[r]!=r)
        r=father[r];
    int i=n,j;
    while(i!=r){
        j=father[i];
        i=j;
        father[i]=r;
    }
    return r;
}

int main()
                         {
    int x,i,j,n;
    int a,b,c;
    while(1)
{
        scanf("%d",&n);//�����ܹ���n������
        if(n==0) break;
        else{
         int sum=0;//����Ϊ0
         for(i=0;i<(n*(n-1))/2;i++)
             scanf("%d %d %d",&E[i].u,&E[i].v,&E[i].w);//����

          int a,b;
          edge e;
          for(i=0;i<(n*(n-1))/2-1;i++)
             for(j=0;j<(n*(n-1))/2-1-i;j++)
                if(E[j].w>E[j+1].w)      {
                    e=E[j];
                    E[j]=E[j+1];
                    E[j]=e;           }
                               //����Ȩֵ��������,�ṹ����ΪȨֵ��С��������
for(i=0;i<(n*(n-1))/2;i++)
    printf("%d",E[i].w);
         int father[101]={0};//���ڵ�����,����ֵ;ÿ�����еĸ��ڵ㶼���Լ�
         for(j=1;j<n+1;j++)
            father[j]=j;
         j=1;
         while(j<n){//��Ҫn-1����
             int v1,v2;
             v1=find_father(father,E[j].u);
             v2=find_father(father,E[j].v);
             if(v1!=v2) {
                 sum+=E[j].w;
                 father[v1]=v2;
                        }
            j++;
                   }
        printf("%d\n",sum);
             }

}
    return 0;
                          }
