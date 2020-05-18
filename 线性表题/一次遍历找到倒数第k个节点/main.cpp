#include <iostream>
/*
  链表就地逆置
  只使用指针的变换

  距离-标尺问题
  其实本质是这样
  两个指针永远保持确定的距离k（一个指针移动到末尾 另一个指针肯定是倒数第k个元素）
  本质是这样 很桥面
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
    //1.移动左标尺
    for(int count=0;count<n;count++)
       {if(pfirst==NULL)
         break;
         pfirst=pfirst->next;
       }
       /*
       链表长度不足n
       */
    if(count!=n)
        return NULL;
    //2.保持距离让标尺移动到右端最末尾 左端及即结果
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
    假设不带头节点
    */
    void Find(head,k);
    return 0;
}
