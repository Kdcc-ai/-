#include <iostream>
#include<algorithm>
#include"vector"
#include"compare.h"
using namespace std;
//c++容器vector
//存储任意类型的数据 可以通过下标访问 动态类型数组

//初始化Vector<类型>标识符 初始化Vector<类型>标识符(最大容量)
//初始化Vector<类型>标识符(最大容量，初始所有值)
int main()
{   //基本操作
    vector<int> obj;
    obj.push_back(1);
    obj.push_back(3);
    obj.push_back(0);
    for(int i=0;i<10;i++)
    {
        obj.push_back(i);
    }
    for(int i=0;i<5;i++)
    {
        obj.pop_back();
    }

     cout<<obj.size()<<" ";

     obj.clear();//  清除所有数据
     cout<<obj.size()<<" ";



    //排序功能
    vector<int> obj2;
    obj2.push_back(1);
    obj2.push_back(3);
    obj2.push_back(0);

    //返回手指针 返回尾指针加一
    sort(obj2.begin(),obj2.end());
    for(int i=0;i<obj2.size();i++)
    {
       cout<<obj2[i]<<" ";
    }
     //起始地址 结束的地址+1
    sort(obj2.begin(),obj2.end(),compare2);
    for(int i=0;i<obj2.size();i++)
    {
        cout<<obj2[i]<<" ";
    }



    //利用下标或者迭代器访问
    cout<<"利用迭代器： ";
    vector<int>::iterator it;
    //作用 遍历或指向vector容器中的元素
    //本身就是个指针 指向vector中的元素
    //另外*代表引用
    for(it=obj2.begin();it!=obj2.end();it++)
    {
        cout<<*it<<" ";
    }


    //定义动态二维数组
    vector<vector<int> > obj3(5,vector<int>(6));
    //定义五行六列


    return 0;
}
