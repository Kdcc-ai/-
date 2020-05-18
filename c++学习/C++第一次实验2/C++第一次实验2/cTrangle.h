class cTrangle
{
public:
	cTrangle(double a=0,double b=0);
	~cTrangle();
	double CaculateCir();
	double CaculateArea();
private:
	double x;
	double y;
};

cTrangle::cTrangle(double a, double b)
{
	x = a;
	y = b;
}
cTrangle::~cTrangle(){}
double cTrangle::CaculateCir()
{
	return 2*(x + y);
}
double cTrangle::CaculateArea()
{
	return x * y;
}
#pragma once
