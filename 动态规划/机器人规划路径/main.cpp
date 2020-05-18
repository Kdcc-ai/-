#include <iostream>
using namespace std;
int main()
{
    int m,n;
    int i,j;
    cin>>m>>n;
    int dp[m+1][n+1];
    dp[1][1]=0;
    for(i=1;i<=m;i++)
        dp[i][1]=1;
    for(j=1;j<=n;j++)
        dp[1][j]=1;
    for(i=2;i<=m;i++)
        for(j=2;j<=n;j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
            cout<<dp[m][n];
    return 0;
}
