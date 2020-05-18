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
//���캯��
SetClass::SetClass()
{
}
//���ƹ��캯��
SetClass::SetClass(SetClass &p)
{
    SetClass::a=p.a;
}
//��������
SetClass::~SetClass()
{
    cout<<"SetClass Destroy"<<endl;
}
//ʵ�ּ��ϲ���Ԫ��
void SetClass::Insert()
{
     cout<<"������Ҫ�������������"<<endl;
     int num;
     cin>>num;
     vector<int>::iterator ret;
     ret=find(a.begin(),a.end(),num);
     if(ret!=a.end())
     {
         cout<<"���������и�Ԫ�� ������������"<<endl;
         return;
     }
     SetClass::a.push_back(num);
     cout<<"����ɹ�"<<endl;
     return;
}
//ʵ�ּ���ɾ��Ԫ��
void SetClass::Delete()
{
    if(SetClass::a.size()==0)
    {
        cout<<"�����ѿ� ������ӻ�ϲ�����"<<endl;
        return;
    }
    else
    {
        cout<<"������Ҫɾ������������"<<endl;
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
        cout<<"ɾ���ɹ�"<<endl;
    }
}
//ʵ����ռ��Ϲ���
void SetClass::Clear()
{
    SetClass::a.clear();
    cout<<"��ճɹ�"<<endl;
    return;
}
//ʵ�ּ��Ͻ�����
//����һ����ʢ�Ž������ ������Ƶ�������
void SetClass::InterSet(SetClass &p)
{
    vector<int> ::iterator itr1=SetClass::a.begin();
    vector<int> ::iterator itr2=p.a.begin();
    vector<int> EndSet;
    //��������
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
      cout<<"�����Ͻ��н����ɹ�"<<endl;
    return;
}
//ʵ�ּ��ϲ�����
//����һ����ʢ�Ž������ ������Ƶ�������
void SetClass::MergeSet(SetClass &p2)
{
    vector<int> ::iterator itr1=SetClass::a.begin();
    vector<int> ::iterator itr2=p2.a.begin();
    vector<int> EndSet;
    //��������
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
     cout<<"�ϲ��ɹ�"<<endl;
    return;
}
//ʵ��չʾ����Ԫ�ز���
void SetClass::ShowSet()
{
    vector<int> ::iterator itr1=SetClass::a.begin();
    if(SetClass::a.size()==0)
    {
        cout<<"��������Ԫ�� ������������"<<endl;
        return;
    }
    else
    {
       cout<<"����Ԫ���������"<<endl;
       while(itr1!=SetClass::a.end())
       {
        cout<<*itr1<<endl;
        ++itr1;
       }
    }
      cout<<"����ɹ�"<<endl;
    return;
}
int main()
{
    SetClass SetVar;
    /*
    ģ��vector����
    */
    SetClass p;
    p.a.push_back(1);
    p.a.push_back(2);
    p.a.push_back(3);
    p.a.push_back(4);
    p.a.push_back(5);
    /*
    ģ��ʵ�ֵ��ø��ƹ��캯������
    */
    SetClass p2(p);
    int choice;
    while(1)
    {
        cout<<"1-����Ԫ��"<<endl;
        cout<<"2-ɾ��Ԫ��"<<endl;
        cout<<"3-��ռ���"<<endl;
        cout<<"4-�����Ϻϲ�"<<endl;
        cout<<"5-�����Ͻ�"<<endl;
        cout<<"6-������ʾ���"<<endl;
        cout<<"7-�˳�ϵͳ"<<endl;
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

