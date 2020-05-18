#include <iostream>
#include<string.h>
#include<stdlib.h>
#include"Set.h"
//向整数集合中添加 若干个元素(判断是否存在)
//从该集合中删除某些元素(需要判断是否存在)
//判断指定元素是否存在
//(使用链表)


//cpp中输出cout<<" "<<" "   cout<<  <<
//或者cout<<" "<<endl

//数组保存

//集合建立->处理->s输出

//unsigned类型(无符号类型)
//能保存2倍与有符号类型的正整数数据
//因为在计算机中 整数是以补码的形式存在的
//无符号类型最高位 不视为符号位
using namespace std;
Set* Initialize()
{
  Set *pSet;
  pSet=(Set*)malloc(sizeof(Set));
  pSet->count==0;
  return pSet;
}//初始化
int Isin(int elem,Set* pSet)
{   int flag=0;
    for(unsigned i=0;i<pSet->count;i++)
    {
        if(elem==pSet->data[i])
             flag=1;
    }
    if(flag==1) return 1;
    else return 0;
}
void Remove(int elem,Set *pSet)
{   unsigned i=0;
    for(i=0;i<pSet->count;i++)
    {
        if(elem==pSet->data[i])
        break;
    }
    if(i<pSet->count)
        pSet->data[i]=pSet->data[(pSet->count--)-1];
    else
        cout<<"待删除元素"<<elem<<"不在集合中。"<<endl;
}
void Add(int elem,Set *pSet)
{
    if(pSet->count<MAXIENGTH)
        if(Isin(elem,pSet)==0)
    {
        pSet->data[(pSet->count)++]=elem;
    }
}
//"."适用于结构体变量 "->"适用于结构体指针变量
int main()
{
    int element,choice;
    Set *s=Initialize();//集合
    cout<<s->count<<" ";
    while(1)
    {
        cout<<"1-添加元素"<<endl;
        cout<<"2-删除元素"<<endl;
        cout<<"3-输入元素判断其是否存在于数组中"<<endl;
        cout<<"4-退出程序"<<endl;
        cout<<"输入您的选择"<<endl;
        cin>>choice;
        switch(choice)
        {
          case 1:
             cout<<"输入您要添加的元素"<<endl;
             cin>>element;
             Add(element,s);//添加
             break;
          case 2:
             cout<<"输入您要删除的元素"<<endl;
             cin>>element;
             Remove(element,s);//删除
             break;
          case 3:
             cout<<"输入您要查询的元素"<<endl;
             cin>>element;
             if(Isin(element,s)==1)//查询
                cout<<"在集合中"<<endl;
             else
                cout<<"不在集合中"<<endl;//判断是否在集合中
             break;
        }
        if(choice==4)
        {
            break;
        }
    }
    return 0;
}
