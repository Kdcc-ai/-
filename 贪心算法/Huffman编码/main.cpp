#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <cstdio>
#define MAX 1000
using namespace std;
/*
贪心策略:
通过合并来构造一棵哈夫曼树的过程
可以从合并两个权值最小的字符开始。
方法：
    （1）由给定的n个权值{w1，w2，…，wn}
    构造n棵只有一个叶子结点的二叉树，
    从而得到一个二叉树的集合F={T1，T2，…，Tn}。
    （2）在F中选取根结点的权值最小和次小的两棵二叉树
    作为左、右子树构造一棵新的二叉树，这棵新的二叉树根结点的权值为其左、右子树根结点权值之和。
    即合并两棵二叉树为一棵二叉树。
    （3）重复步骤（2），
    当F中只剩下一棵二叉树时，这棵二叉树便是所要建立的哈夫曼树。
堆：
     堆就是用数组表示完全二叉树。
     如果每个结点存的值都大于等于自己所有的子节点的值，
     这个堆就叫做“大根堆”；
     反之就叫做“小根堆”。
*/
int n;
struct HTreeNode
{
    char data;
    int weight;
    int parent;
    int lchild;
    int rchild;
};
HTreeNode ht[MAX];//存放节点信息
map<char,string> htcode;//存放哈夫曼编码
//存放优先队列中的节点信息
struct NodeType
{
    int no;
    char data;
    int weight;
    bool operator<(const NodeType &s) const //用于创建小根堆 从小到大排序的
    {
        return s.weight<weight;
    }
};
void CreateTree()
{
    NodeType e,e1,e2;
    priority_queue<NodeType> qu; //优先队列 加入的各个点是按权重永远是由小到大进行排序的！！
         //其实是创建了一个小根堆(每个节点存的值都小于等于自己所有的子节点的值)
    for(int k=0;k<2*n-1;k++)  //设置所有节点的指针域
                              //0~2n-2
        ht[k].lchild=ht[k].rchild=ht[k].parent=-1;
    for(int i=0;i<n;i++)//将n个结点进队qu
    {
        e.no=i;e.data=ht[i].data;
        e.weight=ht[i].weight;
        qu.push(e);
    }

    for(int j=n;j<2*n-1;j++) //构造哈夫曼树的n-1个非叶子节点
    {
        //先出队两个节点
        e1=qu.top();qu.pop();
        e2=qu.top();qu.pop();
        ht[j].weight=e1.weight+e2.weight;
        ht[j].lchild=e1.no;
        ht[j].rchild=e2.no;
        ht[e1.no].parent=j;
        ht[e2.no].parent=j;

        //紧接着进行入队
        e.no=j;
        e.weight=e1.weight+e2.weight;
        qu.push(e);
    }
}
void CreateHCode()		      //构造哈夫曼编码
{  string code;
   code.reserve(MAX);
   for (int i=0;i<n;i++)	      //构造叶子结点i的哈夫曼编码
   {  code="";
      int curno=i;
      int f=ht[curno].parent;
      while (f!=-1)		      //循环到根结点
      {  if (ht[f].lchild==curno)  //curno为双亲f的左孩子
            code='0'+code;
         else			      //curno为双亲f的右孩子
            code='1'+code;
         curno=f;
         f=ht[curno].parent;
      }
      htcode[ht[i].data]=code;     //得到ht[i].data字符的哈夫曼编码
      //哈夫曼编码是01010001...的形式
   }
}
int main()
{
    return 0;
}
