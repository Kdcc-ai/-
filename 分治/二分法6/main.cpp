#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
#define exp 1e-9
#define PI acos(-1.0)
//Cup hdu
double f(double r,double R,double l,double H)
{
   double k=(R-r)*l/H + r;
   return PI*l*(r*r+k*k+k*r)/3;
}
int main()
{
    double r,R,H,V,mid;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>r>>R>>H>>V;
        if(PI*(r*r+R*R+R*r)*H/3<V)
        {
            printf("%.6lf\n",H);
            continue;
        }
        if(r==R)
        {
            printf("%.6lf\n",V/(PI*R*R));
            continue;
        }
        double l=0;
        double ri=H;
        //0~h进行二分
        double v1;
        //精度为右边-左边小于等于1e-10
        while(ri-l>exp)
        {
            mid=(l+ri)/2;
            v1=f(r,R,mid,H);
            if(v1>V) ri=mid;
            else l=mid;
        }
        printf("%.6lf",l);
    }
    return 0;
}
