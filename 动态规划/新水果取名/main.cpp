#include <iostream>
#include <stdio.h>
#include <cstring>
/*
状态方程 dp(m,n)=
{
        dp(m-1,n-1)+1  当s1[m]==s1[n]
        min(dp(m-1,n)+1,dp(m,n-1)+1) 当s1[m]!=s2[n]
}
*/
using namespace std;
int main()
{
    char s1[20],s2[20];
    cin>>s1>>s2;
    int m,n;
    m=strlen(s1);
    n=strlen(s2);
    int i,j;
    char z[m+n+1];
    int dp[m+1][n+1],S[m+1][n+1];
    /*
    和求两个序列的最大公共子序列不同。
    这个地方要进行初始化。
    */
    for(i=1;i<=m;i++)
        S[i][0]=2;
    for(i=1;i<=m;i++)
        S[0][i]=3;
    for(i=0;i<=n;i++)
        dp[i][0]=i;
    for(j=0;j<=n;j++)
        dp[0][j]=j;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
             if(s1[i-1]==s2[j-1])
            {dp[i][j]=dp[i-1][j-1]+1; S[i][j]=1;}
             else if(dp[i][j-1]>dp[i-1][j])
            {dp[i][j]=dp[i-1][j]+1;S[i][j]=2;}
             else
            {dp[i][j]=dp[i][j-1]+1;S[i][j]=3;}
        }
      i=m;j=n;
      int k=dp[m][n];
      while(i>=0&&j>=0)
      {
       if(S[i][j]==1) {z[k]=s1[i-1];k--;i--;j--;}
       else if(S[i][j]==2) {z[k]=s1[i-1];k--;i--;}
       else if(S[i][j]==3) {z[k]=s2[j-1];k--;j--;}
       else break;
      }
      for(i=1;i<=dp[m][n];i++)
         cout<<z[i];
    return 0;
}
