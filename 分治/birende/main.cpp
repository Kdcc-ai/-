#include <iostream>
#include<cstring>
using namespace std;
class Test
{
   public:
      Test(const char *nam,int ag):age(ag){strcpy(name,nam);}
      char* Getname(){return name;}
      int Getage(){return age;}
   private:
      char name[5];
      int age;
};
ostream& operator<<(ostream& out,Test& t1)
{
    out<<t1.Getname()<<" "<<t1.Getage();
    //�ڲ�ʵ�����~
    return out;
}
istream& operator>>(istream &in,Test & t2)
{
    char name[5]={0};
    int age=0;
    in>>name>>age;
    //�ڲ�ʵ������~
    if(in)
    {
        strcpy(t2.Getname(),name);
        ///t2.Getage()=age;
    }
    else{}
    return in;
}
void h(int & 5,)
{

}
int main( )
{
   Test t1("Mike",21);
   cout<<t1<<endl;//���
   cin>>t1;//����
   cout<<t1<<endl;//���
   return 0;
}
