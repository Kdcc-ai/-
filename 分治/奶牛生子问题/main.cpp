#include <iostream>

using namespace std;
CalCowsNum(int n)
{
    int iCnt=0;
    int Cout=1;
    for(iCnt=1;iCnt<=n;iCnt++)
    {
        if(iCnt>=4)//�����꿪ʼ����
        {
            if((n-iCnt)>3)
                //���ĵ�1ֻ��ţ��4�꿪ʼ����
                //���ĵ�2ֻ��ţ��8�꿪ʼ����
                //�ֽ�������
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
