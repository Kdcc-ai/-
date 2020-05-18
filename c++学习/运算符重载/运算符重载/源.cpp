#include <iostream>
using namespace std;
class CComplex
{
	float real, imag;
public:
	CComplex(float xx = 0, float yy = 0) { real = xx; imag = yy; }
	~CComplex() { }
	CComplex operator+(const CComplex &q);
	CComplex operator-(const CComplex &q);
	bool operator == (CComplex);
	bool operator !=(CComplex);
	CComplex operator+=(CComplex);
	CComplex operator-=(CComplex);
	CComplex operator,(CComplex);
	float get_real() { return real; }
	float get_imag() { return imag; }
};
//+运算符
CComplex CComplex::operator+(const CComplex &q)
{
	return CComplex(real + q.real, imag + q.imag);
}
//-运算符
CComplex CComplex::operator-(const CComplex &q)
{
	return CComplex(real - q.real, imag - q.imag);
}
bool CComplex::operator==(CComplex q)
{
	if (real == q.real&&imag == q.imag) return 1;
	return 0;
}
bool CComplex::operator!=(CComplex q)
{
	if (real != q.get_real() || imag != q.get_imag()) return 1;
	return 0;
}
CComplex  CComplex::operator+=(CComplex q)
{
	real += q.real; imag += q.imag;
	return *this;
}
CComplex CComplex ::operator-=(CComplex q)
{
	real -= q.real; imag -= q.imag;
	return *this;
}
CComplex CComplex ::operator,(CComplex q)
{
	return CComplex(q.real, q.imag);
}
int main()
{
	CComplex k1(1, 2), k2(3, 4), k3(5, 6);
    //将k2+k3赋给k1
	cout << "(k1,k2+k3):" << (k1, k2 + k3).get_real() << endl;
	return 0;
}
