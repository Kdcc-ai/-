#include <iostream>

using namespace std;
//Ҫ��ʱ�� �ռ価���ܸ�Ч
void move(int a[],int left,int right)
{   int temp;
    int i;
    if(left==0)
        //Ϊ������ѭ��
        //���left==0 ��ô����0~����
        //��������������0~10��0~9-p
    {       i=left;
            while(i!=right/2){
        temp=a[i];
        a[i]=a[right-i];
        a[right-i]=temp;
        i++;}//R����ת�õõ�
    }
    else
    //���left��=0 ��ô���õ���10-p~
    //��������������10-p~9
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
    cout<<"����p"<<endl;
    cin>>p;
    move(a,0,9);
    //�Ⱦ͵�����
    move(a,0,9-p);
    //0~9-pλ������
    move(a,10-p,9);
    //10-p~9λ������
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
    return 0;
}
