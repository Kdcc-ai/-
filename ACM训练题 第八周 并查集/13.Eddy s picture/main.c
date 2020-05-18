#include <stdio.h>
#include <stdlib.h>
#include<math.h>
//理解好冒泡法排序,从0开始的和从1开始的不一样啊！！
float a[105]={0},b[105]={0};
int father[105];
typedef struct edge{
int u;
int v;
float w;
}edge;
int find_(int a)
{   int m=a;
    while(father[a]!=a)
        a=father[a];
    father[m]=a;
    return a;
}
int main()
{
    int n;
    while(~scanf("%d",&n))     {
        edge E[5000];
        float x,y;
        int i,j;
        int begin=1;
        for(i=1;i<=n;i++){
          scanf("%f %f",&x,&y);
          a[i]=x;
          b[i]=y;
          father[i]=i; }

        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                 if(i<j)
            {
                 E[begin].u=i;
                 E[begin].v=j;
                 E[begin++].w=sqrt((a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]));

            }
            edge temp;
       for(i=1;i<(n-1)*n/2;i++)
         for(j=1;j<(n-1)*n/2-i+1;j++)
           if(E[j].w>E[j+1].w){
              temp=E[j];
              E[j]=E[j+1];
              E[j+1]=temp;
                           }//边按权值进行排序
      //for(i=1;i<=(n-1)*n/2;i++) printf("%.2f\n",E[i].w);
     int num=0;

     float summ=0;

     int begein2=1;
     while(num!=(n-1)){
        int u1=find_(E[begein2].u);
        int v1=find_(E[begein2].v);
        if(u1!=v1)
           {
            father[v1]=u1;
             num++;
            summ+=E[begein2].w;
             begein2++;
           }
        else begein2++;

                      }

    printf("%.2f\n",summ);

                             }
    return 0;
}
