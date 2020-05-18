#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
typedef struct point
{
	double x, y;
}point;
void quicksort(point po[], int left, int right)
{
	point temp, t;
	if (n <= 3) return;
	int i = left;
	int j = right;
	temp = po[left];
	while (i != j)
	{
		while (po[j].x >= temp.x&&i < j)
			j--;
		while (po[i].x <= temp.x&&i < j)
			i++;
		if (i < j)
		{
			t = po[i];
			po[i] = po[j];
			po[j] = t;
		}
	}
	po[left] = po[i];
	po[i] = temp;
	quicksort(po, left, i - 1);
	quicksort(po, i + 1, right);
}
/*
  排序参数
*/
bool Comp(const point &p1, const point &p2)
{
	return p1.y < p2.y;
}
/*
  计算距离函数
*/
double Distance(point a, point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
/*
  分治法求解
*/
double Closest(point po[], int low, int high)
{
	//只有两个点
	if (high - low == 1)
		return Distance(po[low], po[high]);
	//只有三个点
	if (high - low == 2)
	{
		double d1 = Distance(po[low], po[low + 1]);
		double d2 = Distance(po[low + 1], po[high]);
		double d3 = Distance(po[low], po[high]);
		if ((d1 < d2) && (d1 < d3))
			return d1;
		else if (d2 < d3) return d2;
		else return d3;
	}
	//递归求解子问题
	double d;
	double d1, d2;
	int mid = (low + high) / 2;
	d1 = Closest(po, low, mid);
	d2 = Closest(po, mid + 1, high);
	if (d1 <= d2) d = d1;
	else d = d2;

	point P[100];
	//x坐标在-d~+d之间的点并入一个集合
	int index = 1;
	for (int i = mid; (i >= low) && (po[mid].x - po[i].x) < d; i--)
		P[index++] = po[i];
	for (int i = mid + 1; (i <= high) && (po[i].x - po[i].x) < d; i++)
		P[index++] = po[i];

	sort(&P[1], &P[index - 1], Comp);
	//y坐标升序排序
	for (int i = 1; i < index; i++)
		for (int j = i + 1; j < index; j++)
			if ((P[j].y - P[i].y) >= d) break;
			else
			{
				double d3 = Distance(P[i], P[j]);
				if (d3 < d) d = d3;
			}
	return d;
}
/*
主函数
*/
int main()
{
	cout << "输入点的对数N(N>=2)" << '\n';
	cin >> n;
	point po[100];
	cout << "依次输入各点坐标" << '\n';
	for (int i = 1; i <= n; i++)
		cin >> po[i].x >> po[i].y;
	quicksort(po, 1, n);
	//cout<<"各点之间最短距离为"<<" "<<Closest(po,1,n);
	return 0;
}