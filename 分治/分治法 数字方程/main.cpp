#include <iostream>

using namespace std;
int data[6][6];
void Full(int number,int begin,int size)
{
    int i,j,k;
    if(size==0) return;
    if(size==1)
    {
        data[begin][begin]=number;
        cout<<data[begin][begin]<<endl;
        return;
    }
    i=begin;j=begin;
    for(k=0;k<size-1;k++)
    {
        data[i][j]=number;
        cout<<data[i][j]<<endl;
        number++;
        i++;
    }
    for(k=0;k<size-1;k++)
    {
        data[i][j]=number;
        cout<<data[i][j]<<endl;
        number++;j++;
    }
    for(k=0;k<size-1;k++)
    {
        data[i][j]=number;
        cout<<data[i][j]<<endl;
        number++;i--;
    }
    for(k=0;k<size-1;k++)
    {
        data[i][j]=number;
        cout<<data[i][j]<<endl;
        number++;
        j--;
    }
    Full(number,begin+1,size-2);
}
int main()
{
    int number=1;
    int begin=0;
    int size=6;
    Full(number,begin,size);
    return 0;
}
