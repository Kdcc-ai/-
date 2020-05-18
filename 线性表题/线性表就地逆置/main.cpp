#include <iostream>
/*
链表就地逆置
  只使用指针的变换
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
    while(p)//直到原链表为空
    {
        /*向后移动一个位置*/
        q = p;
        p = p->next;

        /*头插*/
        q->next = head->next;
        head -> next = q;
    }
}
void Converse2(LinkList *head)
{
    LinkList *dumpLink = new LinkList(-1);//一个哑节点 用于创建新的链表

    LinkList *p = head;
    LinkList *q = head->next;

    while(p) //直到原链表为空
    {
        /*
        头插
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
      头插法 逆置链表初始化为空
      表中节点从原链表依次删除 逐个插入进而逆置链表
      (一边删除一边插)
    */
    Converse1(head);

    /*
      头插法 不含头节点
      思想其实和带头节点头插法差不多
    */
    Converse2(head);
    /*
    递归实现
    递归的目的是遍历到链表的尾节点，
    然后通过逐级回朔将节点的next指针翻转过来(关键在此)
    可以想象成只有两个节点~~
    */
    Converse3(head);
    return 0;
}
