#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <cstdio>
#define MAX 1000
using namespace std;
/*
̰�Ĳ���:
ͨ���ϲ�������һ�ù��������Ĺ���
���ԴӺϲ�����Ȩֵ��С���ַ���ʼ��
������
    ��1���ɸ�����n��Ȩֵ{w1��w2������wn}
    ����n��ֻ��һ��Ҷ�ӽ��Ķ�������
    �Ӷ��õ�һ���������ļ���F={T1��T2������Tn}��
    ��2����F��ѡȡ������Ȩֵ��С�ʹ�С�����ö�����
    ��Ϊ������������һ���µĶ�����������µĶ�����������ȨֵΪ���������������Ȩֵ֮�͡�
    ���ϲ����ö�����Ϊһ�ö�������
    ��3���ظ����裨2����
    ��F��ֻʣ��һ�ö�����ʱ����ö�����������Ҫ�����Ĺ���������
�ѣ�
     �Ѿ����������ʾ��ȫ��������
     ���ÿ�������ֵ�����ڵ����Լ����е��ӽڵ��ֵ��
     ����Ѿͽ���������ѡ���
     ��֮�ͽ�����С���ѡ���
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
HTreeNode ht[MAX];//��Žڵ���Ϣ
map<char,string> htcode;//��Ź���������
//������ȶ����еĽڵ���Ϣ
struct NodeType
{
    int no;
    char data;
    int weight;
    bool operator<(const NodeType &s) const //���ڴ���С���� ��С���������
    {
        return s.weight<weight;
    }
};
void CreateTree()
{
    NodeType e,e1,e2;
    priority_queue<NodeType> qu; //���ȶ��� ����ĸ������ǰ�Ȩ����Զ����С�����������ģ���
         //��ʵ�Ǵ�����һ��С����(ÿ���ڵ���ֵ��С�ڵ����Լ����е��ӽڵ��ֵ)
    for(int k=0;k<2*n-1;k++)  //�������нڵ��ָ����
                              //0~2n-2
        ht[k].lchild=ht[k].rchild=ht[k].parent=-1;
    for(int i=0;i<n;i++)//��n��������qu
    {
        e.no=i;e.data=ht[i].data;
        e.weight=ht[i].weight;
        qu.push(e);
    }

    for(int j=n;j<2*n-1;j++) //�������������n-1����Ҷ�ӽڵ�
    {
        //�ȳ��������ڵ�
        e1=qu.top();qu.pop();
        e2=qu.top();qu.pop();
        ht[j].weight=e1.weight+e2.weight;
        ht[j].lchild=e1.no;
        ht[j].rchild=e2.no;
        ht[e1.no].parent=j;
        ht[e2.no].parent=j;

        //�����Ž������
        e.no=j;
        e.weight=e1.weight+e2.weight;
        qu.push(e);
    }
}
void CreateHCode()		      //�������������
{  string code;
   code.reserve(MAX);
   for (int i=0;i<n;i++)	      //����Ҷ�ӽ��i�Ĺ���������
   {  code="";
      int curno=i;
      int f=ht[curno].parent;
      while (f!=-1)		      //ѭ���������
      {  if (ht[f].lchild==curno)  //curnoΪ˫��f������
            code='0'+code;
         else			      //curnoΪ˫��f���Һ���
            code='1'+code;
         curno=f;
         f=ht[curno].parent;
      }
      htcode[ht[i].data]=code;     //�õ�ht[i].data�ַ��Ĺ���������
      //������������01010001...����ʽ
   }
}
int main()
{
    return 0;
}
