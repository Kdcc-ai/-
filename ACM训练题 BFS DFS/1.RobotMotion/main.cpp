#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
char paths[1005][1005];
int step[1005][1005];
int r,c,start,row,col,exitstep,diestep,diex,diey;
bool die = false;
//DFS
/*���룺ʵ�ֵݹ�Ĺ��̣�һ��Ҫע���������࣬����ָ��ʽ�������߼�˼·��
������ѧ����ȡ����ʽһ������Ҫ��ͬ�������д̫��飬�ظ�����ִ�л���������ʱ�䣬
��˵���п�����Ϊ���ظ���䣬����ʵ��ACĿ��*/

//num������������߲���
//��row�� col�� ��num��
//���N S W E�͵ݹ�num+1��Ѱ�� �ı���������
//��������������� ��ôexitstep��������Ϊnum

//���û�������� Ҳ��������ѭ���� �ж�ֵ���true֤����������
//��ʱ��������һȦȻ���ֻص���һ��ѭ���� ���ѭ������������Ҳ���ܲ������
//���������߹����� step[][]����ȱ�־���ѷ���ͬʱ��־���ʵ��Ǹ�������߲���
//��������ѭ�� diex diey����ѭ�����x y���� diestep�������������߲��� step[diex][diey]���¸�ֵ �������߲�������һ�ε�����ʱ������߲���

//ע����������--������

//˼����DFS�����ļ򵥱��� �ڱ�д������ע������ĸı� ����Ҫ�������ʲô �������Щ�����ڳ���������α仯�� �������Ӧ�Ա仯���Ż�����Ҳ����Ҫ
void solve(int row,int col,int num)
{
    if(row < 0|| col < 0 || row >= r || col >= c) /*��������*/
    {
        exitstep = num;
        return;
    }
    if(step[row][col]) /*����ѭ��*/
    {
        die = true;
        diex = col;
        diey = row;
        diestep = step[row][col];
        step[row][col] = num - step[row][col];
        return;
    }
    //cout<<paths[row][col]<<endl;
    step[row][col] = num;//����������ܹ����˶��ٲ���
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
        solve(0,start,1);//��һ������
        if(die)  //3 step(s) before a loop of 8 step(s)
            cout<< --diestep<<" step(s) before a loop of "<<step[diey][diex]<<" step(s)"<<endl;
        else    //10 step(s) to exit
            cout<<--exitstep<<" step(s) to exit"<<endl;
    }
    return 0;
}
