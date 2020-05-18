#include <iostream>
using namespace std;
//codeforcesÑµÁ·Ìâ
int main()
{
    int n;
    cin>>n;
    int a,b,c,d;
    int x,y,x1,y1,x2,y2;
    while(n--)
    {
        int True=0;
        cin>>a>>b>>c>>d;
        cin>>x>>y>>x1>>y1>>x2>>y2;

        if(x1==x2&&(a>0||b>0))
            True=0;
        else if(y1==y2&&(c>0||d>0))
            True=0;
        else
        {
            x=x+b-a;
            y=y+d-c;
            if(x>=x1&&x<=x2&&y>=y1&&y<=y2)
                True=1;
            else
                True=0;
        }
        if(True) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
