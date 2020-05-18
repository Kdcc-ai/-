#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = 1e5 + 10;
ll mod = 1e9+7;
const int INF=0x3f3f3f3f;
ll dp[MAXN];
ll n;
ll temp;
typedef struct Node {
    int l, r;
    int sum;
    int lazy;
}Tree;
Tree tree[MAXN*4];
void pushdown(int p){
    if(tree[p].lazy)
    {   tree[p<<1].lazy+=tree[p].lazy;
        tree[p<<1|1].lazy+=tree[p].lazy;
        tree[p<<1].sum+=tree[p].lazy*(tree[p<<1].r-tree[p<<1].l+1);
        tree[p<<1|1].sum+=tree[p].lazy*(tree[p<<1|1].r-tree[p<<1|1].l+1);
        tree[p].lazy=0;
    }
}
void build(int p, int l, int r){
    int mid;
    tree[p].l=l;tree[p].r=r;
    tree[p].lazy=0;
    if(l==r){ tree[p].sum=0; return;}
    mid = (l+r)/2;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    tree[p].sum=tree[p<<1].sum+tree[p<<1|1].sum;
}
void change_point(int p, int x, int num)
{   int mid;
    if(tree[p].l==tree[p].r){ tree[p].sum=tree[p].sum+num; return ;   }
    mid = (tree[p].l+tree[p].r)/2;
    if(x<=mid) change_point(p<<1, x, num);
    else change_point(p<<1|1, x, num);
    tree[p].sum=tree[p<<1].sum+tree[p<<1|1].sum;
}

int find(int p, int x, int y){
    int mid;
    if(x<=tree[p].l&&tree[p].r<=y) return tree[p].sum;
    pushdown(p);
    mid = (tree[p].l+tree[p].r)/2;
    if(y<=mid) return find(p<<1, x, y);
    if(x>mid) return find(p<<1|1,x,y);
    return find(p<<1, x, mid) + find(p<<1|1,mid+1,y);
}

int main()
{  dp[2]=1;
    temp=1;
    for(int i=3;i<=MAXN;i++)
    {   dp[i]=(dp[i-1]%mod*((i-1)%mod*temp%mod))%mod;
       temp=(temp*(i-1))%mod;
    }
    ll ans;
    while(cin>>n)
    {   cout<<dp[n]<<endl;
        ll x;
        ll cnt=0;
        ll ans;
        build(1,1,n);
        for(int i=1;i<=n;i++)
        {   cin>>x;
            if(x==n)
            cnt+=0;
            else
            cnt+=find(1,x+1,n);
            change_point(1,x,1);
        }
        if(cnt%2==0)
            ans=dp[n];
        else ans=(-1)*dp[n];
          cout<<ans<<endl;


    }

	return 0;
}
