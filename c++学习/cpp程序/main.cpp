#include <iostream>
#include<algorithm>
#include"vector"
#include"compare.h"
using namespace std;
//c++����vector
//�洢�������͵����� ����ͨ���±���� ��̬��������

//��ʼ��Vector<����>��ʶ�� ��ʼ��Vector<����>��ʶ��(�������)
//��ʼ��Vector<����>��ʶ��(�����������ʼ����ֵ)
int main()
{   //��������
    vector<int> obj;
    obj.push_back(1);
    obj.push_back(3);
    obj.push_back(0);
    for(int i=0;i<10;i++)
    {
        obj.push_back(i);
    }
    for(int i=0;i<5;i++)
    {
        obj.pop_back();
    }

     cout<<obj.size()<<" ";

     obj.clear();//  �����������
     cout<<obj.size()<<" ";



    //������
    vector<int> obj2;
    obj2.push_back(1);
    obj2.push_back(3);
    obj2.push_back(0);

    //������ָ�� ����βָ���һ
    sort(obj2.begin(),obj2.end());
    for(int i=0;i<obj2.size();i++)
    {
       cout<<obj2[i]<<" ";
    }
     //��ʼ��ַ �����ĵ�ַ+1
    sort(obj2.begin(),obj2.end(),compare2);
    for(int i=0;i<obj2.size();i++)
    {
        cout<<obj2[i]<<" ";
    }



    //�����±���ߵ���������
    cout<<"���õ������� ";
    vector<int>::iterator it;
    //���� ������ָ��vector�����е�Ԫ��
    //������Ǹ�ָ�� ָ��vector�е�Ԫ��
    //����*��������
    for(it=obj2.begin();it!=obj2.end();it++)
    {
        cout<<*it<<" ";
    }


    //���嶯̬��ά����
    vector<vector<int> > obj3(5,vector<int>(6));
    //������������


    return 0;
}
