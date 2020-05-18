#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[5]={1,3,4,5,6};
    int B[5]={2,4,6,6,7};
    int end[10];
    int i=0,j=0;
    int k=0;
    while(i<5&&j<5)
    {
        if(A[i]<=B[j]) end[k++]=A[i++];
        else end[k++]=B[j++];
    }
    while(i<5) end[k++]=A[i++];
    while(j<5) end[k++]=B[j++];
    for(i=0;i<10;i++)
    {
        printf("%d",end[i]);
    }
    return 0;
}
