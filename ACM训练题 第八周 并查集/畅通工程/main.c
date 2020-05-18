#include <stdio.h>
#include <stdlib.h>
int father[2000];
void init(int n){
   int i;
   for(i=1;i<=n;i++){
    father[i]=i;
   }
                }
int find(int x){
    while(x!=father[x])
        x=father[x];
    return x;
}
void union_(int x,int y){
    int v1=find(x);
    int v2=find(y);
    if(v1!=v2){
        father[v1]=v2;
    }
                              }
void count(int n){
    int cnt=n-1;
    int i;
    for(i=1;i<=n;i++){
        if(father[i]!=i){
            cnt--;
                        }

    }
    printf("%d\n",cnt);
}

int main()
{
    int m,n;
    int x,y;
    int i;
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        else{
        scanf("%d",&m);
        if(m==0){
            printf("%d\n",n-1);
            continue;
                }
        init(n);
        for(i=0;i<m;i++){
            scanf("%d %d",&x,&y);
            union_(x,y);
                        }
        count(n);
        }
    }
    return 0;
}
