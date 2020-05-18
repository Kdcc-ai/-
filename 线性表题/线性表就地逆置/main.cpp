#include <iostream>
/*
����͵�����
  ֻʹ��ָ��ı任
*/
using namespace std;
typedef struct LinkList
{
    int k;
    LinkList *next;
}LinkList;
LinkList *initial(){}
void Converse1(LinkList *head)
{
    LinkList *p;
    p = head->next;
    head->next=NULL;

    LinkList *q;
    while(p)//ֱ��ԭ����Ϊ��
    {
        /*����ƶ�һ��λ��*/
        q = p;
        p = p->next;

        /*ͷ��*/
        q->next = head->next;
        head -> next = q;
    }
}
void Converse2(LinkList *head)
{
    LinkList *dumpLink = new LinkList(-1);//һ���ƽڵ� ���ڴ����µ�����

    LinkList *p = head;
    LinkList *q = head->next;

    while(p) //ֱ��ԭ����Ϊ��
    {
        /*
        ͷ��
        */
        p->next = dumpLink->next;
        dumpLink->next = p;

        p = q;
        if(q!=NULL)
        {
            q = q->next;
        }
    }
    return dumpLink->next;
}
void Converse3(LinkList *head)
{
    LinkList *newHead;

    if(head==NULL||(head->next==NULL))
        return head;

    newHead = Converse1(head->next);
    head->next->next = head;
    head->next = NULL;
}
int main()
{
    LinkList *head = initial();
    /*
      ͷ�巨 ���������ʼ��Ϊ��
      ���нڵ��ԭ��������ɾ�� ������������������
      (һ��ɾ��һ�߲�)
    */
    Converse1(head);

    /*
      ͷ�巨 ����ͷ�ڵ�
      ˼����ʵ�ʹ�ͷ�ڵ�ͷ�巨���
    */
    Converse2(head);
    /*
    �ݹ�ʵ��
    �ݹ��Ŀ���Ǳ����������β�ڵ㣬
    Ȼ��ͨ���𼶻�˷���ڵ��nextָ�뷭ת����(�ؼ��ڴ�)
    ���������ֻ�������ڵ�~~
    */
    Converse3(head);
    return 0;
}
