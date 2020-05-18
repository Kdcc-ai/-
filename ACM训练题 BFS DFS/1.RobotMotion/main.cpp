#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
char paths[1005][1005];
int step[1005][1005];
int r,c,start,row,col,exitstep,diestep,diex,diey;
bool die = false;
//DFS
/*感想：实现递归的过程，一定要注意代码的整洁，不是指格式，而是逻辑思路，
就像数学的提取公因式一样，不要把同样的语句写太多遍，重复语句的执行会增加运行时间，
简单说，有可能因为的重复语句，不能实现AC目的*/

//num代表的是总行走步数
//在row行 col列 第num步
//如果N S W E就递归num+1次寻找 改变行数列数
//如果是跳出网格了 那么exitstep跳出步数为num

//如果没跳出网格 也就是陷入循环了 判断值变成true证明跳出网格
//这时候是走了一圈然后又回到了一个循环点 这个循环点可能是起点也可能不是起点
//另外在行走过程中 step[][]数组既标志它已访问同时标志访问到那个点的行走步数
//所以陷入循环 diex diey代表循环点的x y坐标 diestep代表陷入点的行走步数 step[diex][diey]重新赋值 用总行走步数减第一次到这点的时候的行走步数

//注意最后输出的--。。。

//思考：DFS搜索的简单变形 在编写程序是注意变量的改变 程序要我们输出什么 输出的这些变量在程序中是如何变化的 另外如何应对变化来优化程序也很重要
void solve(int row,int col,int num)
{
    if(row < 0|| col < 0 || row >= r || col >= c) /*跳出网格*/
    {
        exitstep = num;
        return;
    }
    if(step[row][col]) /*陷入循环*/
    {
        die = true;
        diex = col;
        diey = row;
        diestep = step[row][col];
        step[row][col] = num - step[row][col];
        return;
    }
    //cout<<paths[row][col]<<endl;
    step[row][col] = num;//代表到这个点总共走了多少步！
    if(paths[row][col] == 'N')
        solve(row-1,col,num+1);
    else if(paths[row][col] == 'S')
        solve(row+1,col,num+1);
    else if(paths[row][col] == 'E')
        solve(row,col+1,num+1);
    else if(paths[row][col] == 'W')
        solve(row,col-1,num+1);
}

int main()
{
    while(cin>>r>>c,r||c)
    {
        cin>>start;
        for(int i = 0; i < r; i++)
            scanf("%s",paths[i]);
        memset(step,0,sizeof(step));
        die = false;
        start = start -1;
        solve(0,start,1);//第一次搜索
        if(die)  //3 step(s) before a loop of 8 step(s)
            cout<< --diestep<<" step(s) before a loop of "<<step[diey][diex]<<" step(s)"<<endl;
        else    //10 step(s) to exit
            cout<<--exitstep<<" step(s) to exit"<<endl;
    }
    return 0;
}
