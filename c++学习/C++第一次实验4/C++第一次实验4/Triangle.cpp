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
	 cout << "三角形初始化完成" << endl;
}

 Triangle::~ Triangle()
{
	 cout << "析构函数被调用" << endl;
}
 int main()
 {
	 double x1, y1;
	 cout << "请输入第一个点坐标" << endl;
	 cin >> x1 >> y1;
	 myPoint Point1(x1, y1);
	 cout << "请输入第二个点坐标" << endl;
	 cin >> x1 >> y1;
	 myPoint Point2(x1, y1);
	 cout << "请输入第三个点坐标" << endl;
	 cin >> x1 >> y1;
	 myPoint Point3(x1, y1);

	 double length1 = Point1.GetLength(Point2);
	 double length2 = Point1.GetLength(Point2);
	 double length3 = Point2.GetLength(Point3);
	 cout << "三角形周长为" << fixed << setprecision(2) << length1 + length2 + length3 << endl;
	 double p = (length1 + length2 + length3) / 2;
	 double s = sqrt(p*(p - length1)*(p - length2)*(p - length3));
	 cout << "三角形面接为" << fixed << setprecision(2) << s << endl;
 }