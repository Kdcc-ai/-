#include <iostream>
//青蛙跳多少次都行
using namespace std;

int f(int n)
{
    if(n<2) return n;
    else
    {
        return 2*f(n-1);
    }
}
int main()
{
    int n;
    cout<<"输入n"<<" ";
    cin>>n;
    cout<<f(n);

    return 0;
}
