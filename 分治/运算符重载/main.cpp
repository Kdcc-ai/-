#include<iostream>
using namespace std;
class Test {
    friend ostream& operator<<(ostream& cout,Test t1);
public:
    Test() {
        num = 0;
    }
    //重载++i运算符
    //说明这是一个前缀形式
    Test & operator++() {
        num++;
        return *this;
    }
    //重载i++运算符
    //int在括号里面是为了向编译器说明这是一个后缀形式
    Test operator++(int) {
        //先记录当时结果
       // Test tmp = *this;
        //后递增
        num++;
        //再返回记录的结果
        return *this;
    }
private:
    int num;
};
ostream & operator<<(ostream &cout,Test t1) {
    cout << "num=" << t1.num;
    return cout;
}
int main() {
    Test t1;
    cout << t1++ << endl;
    cout << t1 << endl;
    Test t2;
    cout << ++(++t2)<<endl;
    cout << t2 << endl;
    return 0;
}
