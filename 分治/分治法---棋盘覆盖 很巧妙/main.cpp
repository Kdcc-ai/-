#include <iostream>
using namespace std;
//ʹ�ò�ͬ��״��L�͹��Ƹ��������ϳ����ⷽ����������з���
// 2��k����*2��k���ݸ����� ������һ�����ⷽ��
/*
tr tc �����������Ͻ����� ��СΪs
dr dc���ⷽ�����λ��
�����̱߳�size
*/
int board[101][101]={0};
int t=0;//tΪʹ��L�͹��̸���
void ChessBoard(int tr,int tc,int dr,int dc,int size)
{
    int s,t1;
    if(size==1) return;
    t1=++t;
    s=size/2;
    if(dr<tr+s&&dc<tc+s) //���ⷽ��������Ͻ�������
        ChessBoard(tr,tc,dr,dc,s); //�ݹ鴦�����Ͻ�����
    else{
        board[tr+s-1][tc+s-1]=t1; //t1������Ͻ�����
        ChessBoard(tr,tc,dr+s-1,dc+s-1,s);//�ݹ鴦�����Ͻ�����
    }
    if(dr<tr+s&&dc>=tc+s) //���ⷽ�������Ͻ�������
        ChessBoard(tr,tc+s,dr,dc,s);
    else{
        board[tr+s-1][tc+s]=t1;
        ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }
    if(dr>=tr+s&&dc<tc+s)//���ⷽ�������½�����zhon
        ChessBoard(tr+s,tc,dr,dc,s);
    else{
        board[tr+s][tc+s-1]=t1;
        ChessBoard(tr+s,tc,tr+s,tr+s-1,s);
    }
    if(dr>=tr+s&&dc>=tc+s)//���ⷽ�������½���������
        ChessBoard(tr+s,tc+s,dr,dc,s);
    else{
        board[tr+s][tc+s]=t1;
        ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
    }
}
int main()
{
    int length;
    cin>>length;
   //�������̳���
    int dr;
    int dc;
    cin>>dr>>dc;
    //�������������λ��
     board[dr][dc]=0;
    //���Ͻ����� ���ⷽ��λ�� �����̳���
    ChessBoard(1,1,dr,dc,length);
    for(int i=1;i<=length;i++)
      {
        for(int j=1;j<=length;j++)
    {
        cout.width(2);
        cout<<board[i][j]<<" ";
    }
       cout<<'\n';
      }
    return 0;
}
//ʱ�临�Ӷȸ��ݵݹ鷽�� T(k)=0(4��k����)
