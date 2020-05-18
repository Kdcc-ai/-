#include <iostream>
#include <stdio.h>
using namespace std;
int main()
    {
    FILE *In,*Ou;
    int n,i,j,k;
    int min;
    In=fopen("D:\\input.txt","r");
    fscanf(In,"%d",&n);
    int a[n+1][n],dp[n+1][n];
    for(i=1;i<n;i++) {a[i][i]=0;dp[i][i]=0;}
    for(i=1;i<n;i++) //ÊäÈën-1ÐÐ
       for(j=i+1;j<=n;j++)
           fscanf(In,"%d",&a[i][j]);
    fclose(In);
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
    {
        min = a[i][j];
        for(k=i+1;k<j;k++)
            if(a[i][k]+a[k][j]<min)
                min=a[i][k]+a[k][j];
        a[i][j]=min;
    }
    Ou=fopen("D:\\output.txt","w");
    fprintf(Ou,"%d",a[1][n]);
    fclose(Ou);
    return 0;
}
