#include <iostream>
#include<string.h>
#include<stdlib.h>
#include"Set.h"
//��������������� ���ɸ�Ԫ��(�ж��Ƿ����)
//�Ӹü�����ɾ��ĳЩԪ��(��Ҫ�ж��Ƿ����)
//�ж�ָ��Ԫ���Ƿ����
//(ʹ������)


//cpp�����cout<<" "<<" "   cout<<  <<
//����cout<<" "<<endl

//���鱣��

//���Ͻ���->����->s���

//unsigned����(�޷�������)
//�ܱ���2�����з������͵�����������
//��Ϊ�ڼ������ �������Բ������ʽ���ڵ�
//�޷����������λ ����Ϊ����λ
using namespace std;
Set* Initialize()
{
  Set *pSet;
  pSet=(Set*)malloc(sizeof(Set));
  pSet->count==0;
  return pSet;
}//��ʼ��
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
        cout<<"��ɾ��Ԫ��"<<elem<<"���ڼ����С�"<<endl;
}
void Add(int elem,Set *pSet)
{
    if(pSet->count<MAXIENGTH)
        if(Isin(elem,pSet)==0)
    {
        pSet->data[(pSet->count)++]=elem;
    }
}
//"."�����ڽṹ����� "->"�����ڽṹ��ָ�����
int main()
{
    int element,choice;
    Set *s=Initialize();//����
    cout<<s->count<<" ";
    while(1)
    {
        cout<<"1-���Ԫ��"<<endl;
        cout<<"2-ɾ��Ԫ��"<<endl;
        cout<<"3-����Ԫ���ж����Ƿ������������"<<endl;
        cout<<"4-�˳�����"<<endl;
        cout<<"��������ѡ��"<<endl;
        cin>>choice;
        switch(choice)
        {
          case 1:
             cout<<"������Ҫ��ӵ�Ԫ��"<<endl;
             cin>>element;
             Add(element,s);//���
             break;
          case 2:
             cout<<"������Ҫɾ����Ԫ��"<<endl;
             cin>>element;
             Remove(element,s);//ɾ��
             break;
          case 3:
             cout<<"������Ҫ��ѯ��Ԫ��"<<endl;
             cin>>element;
             if(Isin(element,s)==1)//��ѯ
                cout<<"�ڼ�����"<<endl;
             else
                cout<<"���ڼ�����"<<endl;//�ж��Ƿ��ڼ�����
             break;
        }
        if(choice==4)
        {
            break;
        }
    }
    return 0;
}
