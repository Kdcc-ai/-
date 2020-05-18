#include <iostream>

using namespace std;
void move(char a[],int left,int right)
{
    int k=left,j=right;
    char temp;
    while(k<j)
    {
        temp=a[k];
        a[k]=a[j];
        a[j]=temp;
        k++;
        j--;
    }
}
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    char A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    move(A,0,n-1);
    move(A,0,n-k-1);
    move(A,n-k,n-1);
    for(int i=0;i<n;i++)
        cout<<A[i];
    return 0;
}
