#include<iostream>
#include<iomanip>
#include<cmath>
#include"myPoint.cpp"
using namespace std;
class  Triangle
{
public:
	 Triangle(myPoint x1,myPoint x2,myPoint x3);
	~ Triangle();

private:
	myPoint p1;
	myPoint p2;
	myPoint p3;
};

 Triangle:: Triangle(myPoint x1, myPoint x2, myPoint x3):p1(x1),p2(x2),p3(x3)
{
	 cout << "�����γ�ʼ�����" << endl;
}

 Triangle::~ Triangle()
{
	 cout << "��������������" << endl;
}
 int main()
 {
	 double x1, y1;
	 cout << "�������һ��������" << endl;
	 cin >> x1 >> y1;
	 myPoint Point1(x1, y1);
	 cout << "������ڶ���������" << endl;
	 cin >> x1 >> y1;
	 myPoint Point2(x1, y1);
	 cout << "�����������������" << endl;
	 cin >> x1 >> y1;
	 myPoint Point3(x1, y1);

	 double length1 = Point1.GetLength(Point2);
	 double length2 = Point1.GetLength(Point2);
	 double length3 = Point2.GetLength(Point3);
	 cout << "�������ܳ�Ϊ" << fixed << setprecision(2) << length1 + length2 + length3 << endl;
	 double p = (length1 + length2 + length3) / 2;
	 double s = sqrt(p*(p - length1)*(p - length2)*(p - length3));
	 cout << "���������Ϊ" << fixed << setprecision(2) << s << endl;
 }