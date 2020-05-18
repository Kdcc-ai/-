#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class SetClass{
public:
    vector<int> a;
    SetClass();
    SetClass(SetClass &p);
    ~SetClass();
    void Insert();
    void Delete();
    void Clear();
    void MergeSet(SetClass &p);
    void InterSet(SetClass &p);
    void ShowSet();
};
//构造函数
SetClass::SetClass()
{
}
//复制构造函数
SetClass::SetClass(SetClass &p)
{
    SetClass::a=p.a;
}
//析构函数
SetClass::~SetClass()
{
    cout<<"SetClass Destroy"<<endl;
}
//实现集合插入元素
void SetClass::Insert()
{
     cout<<"输入您要插入的整数数据"<<endl;
     int num;
     cin>>num;
     vector<int>::iterator ret;
     ret=find(a.begin(),a.end(),num);
     if(ret!=a.end())
     {
         cout<<"集合中已有该元素 考虑其他操作"<<endl;
         return;
     }
     SetClass::a.push_back(num);
     cout<<"插入成功"<<endl;
     return;
}
//实现集合删除元素
void SetClass::Delete()
{
    if(SetClass::a.size()==0)
    {
        cout<<"集合已空 考虑添加或合并操作"<<endl;
        return;
    }
    else
    {
        cout<<"输入您要删除的整形数据"<<endl;
        int num;
        cin>>num;
        vector<int> ::iterator itr=SetClass::a.begin();
        while(itr!=SetClass::a.end())
        {
            if(num==*itr)
            {
               itr = SetClass::a.erase(itr);
            }
            else
            {
                itr++;
            }
        }
        cout<<"删除成功"<<endl;
    }
}
//实现清空集合功能
void SetClass::Clear()
{
    SetClass::a.clear();
    cout<<"清空成功"<<endl;
    return;
}
//实现集合交操作
//采用一容器盛放结果数据 最终深复制到集合中
void SetClass::InterSet(SetClass &p)
{
    vector<int> ::iterator itr1=SetClass::a.begin();
    vector<int> ::iterator itr2=p.a.begin();
    vector<int> EndSet;
    //交集操作
    while(itr1!=SetClass::a.end())
    {
        vector<int>::iterator ret;
        ret=find(EndSet.begin(),EndSet.end(),*itr1);
        if(ret!=EndSet.end())
        {
            ++itr1;
            itr2=p.a.begin();
            continue;
        }
        while(itr2!=p.a.end())
        {
            if(*itr1==*itr2)
            {
                EndSet.push_back(*itr1);
                ++itr1;
                itr2=p.a.begin();
                continue;
            }
            else
            {
                if(itr2==p.a.end())
                {
                    ++itr1;
                    itr2=p.a.begin();
                    continue;
                }
                else
                {
                    ++itr2;
                }
            }
        }
    }
    SetClass::a=EndSet;
      cout<<"两集合进行交集成功"<<endl;
    return;
}
//实现集合并操作
//采用一容器盛放结果数据 最终深复制到集合中
void SetClass::MergeSet(SetClass &p2)
{
    vector<int> ::iterator itr1=SetClass::a.begin();
    vector<int> ::iterator itr2=p2.a.begin();
    vector<int> EndSet;
    //并集操作
    while(itr2!=p2.a.end())
    {
        vector<int>::iterator ret;
        ret=find(EndSet.begin(),EndSet.end(),*itr2);
        if(ret!=EndSet.end())
        {
            ++itr2;
            continue;
        }
        else
        {
            EndSet.push_back(*itr2);
        }
    }
    while(itr1!=SetClass::a.end())
    {
        vector<int>::iterator ret;
        ret=find(EndSet.begin(),EndSet.end(),*itr1);
        if(ret!=EndSet.end())
        {
            ++itr1;
            continue;
        }
        else
        {
            EndSet.push_back(*itr1);
        }
    }
    SetClass::a=EndSet;
     cout<<"合并成功"<<endl;
    return;
}
//实现展示集合元素操作
void SetClass::ShowSet()
{
    vector<int> ::iterator itr1=SetClass::a.begin();
    if(SetClass::a.size()==0)
    {
        cout<<"集合中无元素 考虑其他操作"<<endl;
        return;
    }
    else
    {
       cout<<"集合元素输出如下"<<endl;
       while(itr1!=SetClass::a.end())
       {
        cout<<*itr1<<endl;
        ++itr1;
       }
    }
      cout<<"输出成功"<<endl;
    return;
}
int main()
{
    SetClass SetVar;
    /*
    模拟vector容器
    */
    SetClass p;
    p.a.push_back(1);
    p.a.push_back(2);
    p.a.push_back(3);
    p.a.push_back(4);
    p.a.push_back(5);
    /*
    模拟实现调用复制构造函数功能
    */
    SetClass p2(p);
    int choice;
    while(1)
    {
        cout<<"1-插入元素"<<endl;
        cout<<"2-删除元素"<<endl;
        cout<<"3-清空集合"<<endl;
        cout<<"4-两集合合并"<<endl;
        cout<<"5-两集合交"<<endl;
        cout<<"6-集合显示输出"<<endl;
        cout<<"7-退出系统"<<endl;
        cin>>choice;
        switch(choice)
        {
           case 1:
                SetVar.Insert();
                break;
           case 2:
                SetVar.Delete();
                break;
           case 3:
               SetVar.Clear();
               break;
           case 4:
               SetVar.MergeSet(p2);
               break;
           case 5:
               SetVar.InterSet(p2);
               break;
           case 6:
                SetVar.ShowSet();
                break;
        }
        if(choice==7)
            break;
    }
        cout<<"Program End"<<endl;
}

