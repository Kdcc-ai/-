#include<iostream>
using namespace std;
class Test {
    friend ostream& operator<<(ostream& cout,Test t1);
public:
    Test() {
        num = 0;
    }
    //����++i�����
    //˵������һ��ǰ׺��ʽ
    Test & operator++() {
        num++;
        return *this;
    }
    //����i++�����
    //int������������Ϊ���������˵������һ����׺��ʽ
    Test operator++(int) {
        //�ȼ�¼��ʱ���
       // Test tmp = *this;
        //�����
        num++;
        //�ٷ��ؼ�¼�Ľ��
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
