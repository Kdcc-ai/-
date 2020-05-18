#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/**
���Ϊ0�ĵ�ֻ��һ��
��������ĵ���ȶ�Ϊ1
�յ�ͼҲ�ǿ���
*/
//ѧ����Գ���
int father[10010];
int vis[10010];
int in[10010];//��¼���������

int find_t(int m)  {
     int r=m;
     while(father[r]!=r)
        r=father[r];
    int i=m,j;
    while(i!=r){
        j=father[i];
        i=j;
        father[i]=r;
                }
    return r;  }

void merge(int m,int n){
  int A,B;
  A=find_t(m);
  B=find_t(n);
  if(A!=B)
    father[B]=A;
                      }


int main()
{
    int m,n,i;
    int k=1;
    while(~scanf("%d%d",&m,&n)){
        if(m==0&&n==0)   {//ֱ�������˿���
            printf("Case %d is a tree.\n",k);
            k++;
            continue;//������һ��ѭ��
                          }

        for(i=0;i<10010;i++)
        {
            father[i]=i;
            vis[i]=0;
            in[i]=0;//�����鸳��ֵ
        }

        if(m==-1&&n==-1) break;//��һ�ξ������˽�����־
        in[n]++;//��ȼ�1,ָ���Ǹ������ȼ�1
        merge(m,n);//���е�ĺϲ�
        vis[m]=1;
        vis[n]=1;//֤���õ��ѽ���
        scanf("%d %d",&m,&n);
        while(m!=0&&n!=0) {//��������
            in[n]++;
            merge(m,n);
            vis[m]=1;
            vis[n]=1;
        scanf("%d %d",&m,&n);
                                           }

        int res=0;
        int res2=0;
        for(i=1;i<10010;i++){
            if(vis[i]==1&&in[i]==0) res++;//�����жϸ��ڵ�
            if(vis[i]==1&&in[i]>=2) res2++;//�����ж��Ƿ�������Ϊ2�ĵ�
        }
        if(res==1&&res2==0) {
                printf("Case %d is a tree.\n",k);
                k++;
                continue;
             }
        else{
              printf("Case %d is not a tree.\n",k);
              k++;
              continue;
             }
                              }
    return 0;
}
