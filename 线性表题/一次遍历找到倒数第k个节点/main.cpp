#include <iostream>
/*
  ����͵�����
  ֻʹ��ָ��ı任

  ����-�������
  ��ʵ����������
  ����ָ����Զ����ȷ���ľ���k��һ��ָ���ƶ���ĩβ ��һ��ָ��϶��ǵ�����k��Ԫ�أ�
  ���������� ������
*/
using namespace std;
typedef struct LinkList
{
    int k;
    LinkList *next;
}LinkList;
LinkList *initial(){}
void Find(LinkList *head,int n)
{
    if(head==NULL||k==0)
    {
      return NULL;
    }
    LinkList *pfirst=head;
    LinkList *pseconf=head;
    //1.�ƶ�����
    for(int count=0;count<n;count++)
       {if(pfirst==NULL)
         break;
         pfirst=pfirst->next;
       }
       /*
       �����Ȳ���n
       */
    if(count!=n)
        return NULL;
    //2.���־����ñ���ƶ����Ҷ���ĩβ ��˼������
    while(pfirst!=NULL)
    {
        pfirst=pfirst->next;
        pseconF=pseconf->next;
    }
    cout<<pseconf->k<<endl;
}
int main()
{
    LinkList *head = initial();
    /*
    ���費��ͷ�ڵ�
    */
    void Find(head,k);
    return 0;
}
