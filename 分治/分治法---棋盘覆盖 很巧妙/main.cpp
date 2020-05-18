#include <iostream>
using namespace std;
//使用不同形状的L型骨牌覆盖棋盘上除特殊方格以外的所有方格
// 2的k次幂*2的k次幂个方格 其中有一个特殊方格
/*
tr tc 子棋盘中左上角坐标 大小为s
dr dc特殊方格放置位置
子棋盘边长size
*/
int board[101][101]={0};
int t=0;//t为使用L型骨盘个数
void ChessBoard(int tr,int tc,int dr,int dc,int size)
{
    int s,t1;
    if(size==1) return;
    t1=++t;
    s=size/2;
    if(dr<tr+s&&dc<tc+s) //特殊方格放在左上角棋盘中
        ChessBoard(tr,tc,dr,dc,s); //递归处理左上角棋盘
    else{
        board[tr+s-1][tc+s-1]=t1; //t1填充左上角棋盘
        ChessBoard(tr,tc,dr+s-1,dc+s-1,s);//递归处理左上角棋盘
    }
    if(dr<tr+s&&dc>=tc+s) //特殊方格在右上角棋盘中
        ChessBoard(tr,tc+s,dr,dc,s);
    else{
        board[tr+s-1][tc+s]=t1;
        ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }
    if(dr>=tr+s&&dc<tc+s)//特殊方格在左下角棋盘zhon
        ChessBoard(tr+s,tc,dr,dc,s);
    else{
        board[tr+s][tc+s-1]=t1;
        ChessBoard(tr+s,tc,tr+s,tr+s-1,s);
    }
    if(dr>=tr+s&&dc>=tc+s)//特殊方格在右下角子棋盘中
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
   //输入棋盘长度
    int dr;
    int dc;
    cin>>dr>>dc;
    //输入特殊点所在位置
     board[dr][dc]=0;
    //左上角坐标 特殊方格位置 总棋盘长度
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
//时间复杂度根据递归方程 T(k)=0(4的k次幂)
