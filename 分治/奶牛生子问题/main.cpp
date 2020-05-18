#include <iostream>

using namespace std;
CalCowsNum(int n)
{
    int iCnt=0;
    int Cout=1;
    for(iCnt=1;iCnt<=n;iCnt++)
    {
        if(iCnt>=4)//第四年开始生羊
        {
            if((n-iCnt)>3)
                //生的第1只奶牛第4年开始生羊
                //生的第2只奶牛第8年开始生羊
                //分解子问题
                Cout+=CalCowsNum(n-iCnt);
        }
        else
            Cout++;
    }
    return Cout;
}

int main()
{
    int k=CalCowsNum(20);
    cout<<k;
    return 0;
}
