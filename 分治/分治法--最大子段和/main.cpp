#include<iostream>
using namespace std;
main() {
    int a=1;
    //define是字面替换
    #define T1 a+a
    #define T2 T1-T1
    cout<<"T2 is "<<T2<<endl;
    return 0;
        }
  //输出结果
