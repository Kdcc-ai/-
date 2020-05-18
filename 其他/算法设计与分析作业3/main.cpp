#include <iostream>

using namespace std;
//要求时间 空间尽可能高效
void move(int a[],int left,int right)
{   int temp;
    int i;
    if(left==0)
        //为避免死循环
        //如果left==0 那么逆置0~××
        //在这题中是逆置0~10、0~9-p
    {       i=left;
            while(i!=right/2){
        temp=a[i];
        a[i]=a[right-i];
        a[right-i]=temp;
        i++;}//R数组转置得到
    }
    else
    //如果left！=0 那么逆置的是10-p~
    //在这题中是逆置10-p~9
    {
        while(left!=right){
            temp=a[left];
            a[left]=a[right];
            a[right]=temp;
            left++;
            right--;}
    }
}
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int p;
    cout<<"输入p"<<endl;
    cin>>p;
    move(a,0,9);
    //先就地逆置
    move(a,0,9-p);
    //0~9-p位置逆置
    move(a,10-p,9);
    //10-p~9位置逆置
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
    return 0;
}
