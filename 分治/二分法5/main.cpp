#include <iostream>
#include<stdio.h>
#include<cmath>
//Can you solve this equation?
using namespace std;
int x,y;
//比较简单 典型二分
double f(double number)
{
    return 8*pow(number,4)+7*pow(number,3)+2*pow(number,2)+3*number+6;
}
int main()
{
    int T;
    scanf("%d",&T);
        while(T--)
        {
            double low=0,up=100,f1,f2;
            double mid;
            scanf("%d",&y);
            f1=f(low);f2=f(up);
            if(f1>y||f2<y)
            {
                cout<<"No solution"<<endl;
            }
            else
                {
            while(fabs((f1-y)-(f2-y))>=1e-5)
            {
                    mid=(low+up)/2;
                    if(f(mid)<y) low=mid;
                    else up=mid;
                    f1=f(low);f2=f(up);
            }
               printf("%.4f\n",mid);
                  }
        }

    return 0;
}
