#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int father[10000010];
int ins[10000010];
int find(int a){
 int r=a;
 while(r!=father[r]){
    r=father[r];
                    }
    int i=a,j;
    while(i!=r){
        j=father[i];
        i=j;
        father[i]=r;
                }
 return r;
}
int merge(int a,int b){
  int A=find(a);
  int B=find(b);
  if(A!=B)
    father[A]=B;
                      }
int main()
{
    int m;
    while(~scanf("%d",&m)){
    int i=0;
    int a,b;
    for(i=0;i<=10000000;i++){
        ins[i]=0;
    }
    for(i=1;i<=10000000;i++)
        father[i]=i;
    for(i=0;i<m;i++)
    {scanf("%d %d",&a,&b);
      merge(a,b);
    }
    for(i=1;i<=10000000;i++)
    { ins[find(i)]++;
    }
    int max=0;
    for(i=1;i<=10000000;i++)
        if(ins[i]>max) max=ins[i];
     printf("%d\n",max);
    }
    return 0;
}
