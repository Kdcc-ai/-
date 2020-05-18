#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 1000+10
int p[N];
int n,m,a,b;
int find(int x){
  while(x!=p[x])
    x=p[x];
  return x;
}
void ks(){
  int i;
  for(i=1;i<=n;i++) p[i]=i;
  while(m--){
    scanf("%d %d",&a,&b);
    int x=find(a),y=find(b);
    if(x!=y){
        p[y]=x;
        n--;
    }
  }
}
int main()
{
    int t;
    scanf("%d",&t);//输入t个用例
    while(t--){
        memset(p,0,sizeof(p));
        scanf("%d%d",&n,&m);//n个人
        ks();
        printf("%d\n",n);
    }
    return 0;
}
