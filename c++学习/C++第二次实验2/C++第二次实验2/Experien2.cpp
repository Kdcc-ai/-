#include<cmath>
#include<iostream>
using namespace std;
class Point{
public:
	Point() { x = 0; y = 0; }
	Point(double xv,double yv) { x = xv; y = yv; }
	Point(Point& pt) { x = pt.x;  y = pt.y; }
	double getx() { return x; }
	double gety() { return y; }
	double Area() { return 0; }
	void Show() { cout << "x=" << x << ' ' << "y=" << y << endl; }
private:
	double x,y;
};
class Rectangle:public Point
{
public:
	Rectangle(double x1, double y1) :Point() { xLong = x1; yLong = y1; }
	Rectangle(double x, double y, double xl, double yl) :Point(x, y) { xLong = xl; yLong = yl;}
	Rectangle(Point &p, double x1, double y1) :Point(p) { xLong = x1; yLong = y1; }
	void position(Point &pt) 
	{
		double ptGetx = pt.getx(), ptGety = pt.gety();
		if (ptGetx> Point::getx() && ptGety<Point::getx()+xLong && ptGety>Point::gety() && ptGety< Point::gety() +yLong)
		{
			cout << "点" << pt.getx() << "," << pt.gety()<< "在矩形内" << endl;
		}
		else if(ptGetx<Point::getx()||ptGetx>Point::getx() +xLong||ptGety<Point::gety() ||ptGety>Point::gety() +yLong)
		{
			cout << "点" << pt.getx() << "," << pt.gety() << "在矩形外" << endl;
		}
		else
		{
			cout << "点" << pt.getx() << "," << pt.gety() << "在矩形边缘上" << endl;
		}
	}
private:
	double xLong;
	double yLong;
};
class Circle :public Point
{
public:
	Circle(double r1) :Point() { radius=r1; }
	Circle(double x, double y, double r1) :Point(x, y) { radius=r1; }
	Circle(Point &p, double r1) :Point(p) { radius = r1; }
	void position(Point &pt)
	{
		double ptGetx = pt.getx();
		double ptGety = pt.gety();
		cout << abs(ptGety - Point::gety()) - radius << endl;
		if (fabs(ptGetx - Point::getx()) < radius&&fabs(ptGety - Point::gety()) < radius)
		{
			cout << "点" << pt.getx() << "," << pt.gety() << "在圆形内" << endl;
		}
		else if(  fabs(ptGetx - Point::getx()-radius)<1e-7 && fabs(ptGety - Point::gety()-radius)<1e-7  )
		{
			cout << "点" << pt.getx() << "," << pt.gety() << "在圆形边缘上" << endl;
		}
		else
		{
			cout << "点" << pt.getx() << "," << pt.gety() << "在圆形外" << endl;
		}
	}
private:
	double radius;
};
int main()
{
	Rectangle t1(0, 0, 1.5, 1.5);
	Point p1(1.5, 1.5);
	t1.position(p1);
	Point p2(0.8, 0.8);
	t1.position(p2);
	Point p3(1.7, 2.1);
	t1.position(p3);

	Circle c1(1.1, 1.2, 1.5);
	Point p4(2.6, 2.7);
	c1.position(p4);
	Point p5(1.3, 1.5);
	c1.position(p5);
	Point p6(2.9, 2.8);
	c1.position(p6);
	return 0;
}