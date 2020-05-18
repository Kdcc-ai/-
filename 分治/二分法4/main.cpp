#include<iostream>
#include<cmath>
#include<stdio.h>
const double eps=1e-9;
double X,Y,L,D;
double PI=acos(-1.0);
//Èý·Ö·¨
double distance(double angle)
{
 return(-X+L*sin(angle)+D/cos(angle))/tan(angle);
}
int main()
{
   while(scanf("%lf %lf %lf %lf",&X,&Y,&L,&D)!=EOF)
   {
      if(X<D||Y<D)
      {
        printf("no\n");
        continue;
      }
      double low=0,up=PI/2,mid,mmid;
      double dis1,dis2;
      while(true)
      {
               mid = (low + up) / 2;
               mmid = (mid + up) / 2;
               dis1 = distance(mid);
               dis2 = distance(mmid);
              if(dis1 > dis2) up = mmid;
              else low = mid;
              if(up - low < eps) break;
     }
     if((dis1)<=Y)
     printf("yes\n");
     else
     printf("no\n");
   }
}


