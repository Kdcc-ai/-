#include <iostream>
using namespace std;

int main()
{
    int N,a[25],L[25];
    while(cin>>N)
    {
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
            L[i]=1;
        }
        int i;
        for(i=1;i<N;i++)
        {
            int max=1;
            for(int j=i-1;j>=0;j--)
                if((a[j]>=a[i])&&(max<L[j]+1))
            {
                max=L[j]+1;
                L[i]=max;
            }
        }
        int index;
        for(index=0,i=1;i<N;i++)
            if(L[index]<L[i])
               index=i;
        cout<<L[index]<<endl;
    }
    return 0;
}
