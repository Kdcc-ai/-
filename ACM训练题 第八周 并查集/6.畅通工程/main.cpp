
#include<iostream>

#include<vector>



using namespace std;



//�����һ���õ����鼯������



int father[10000];//����һ������



void init(int n) {

	for (int i = 1; i <= n; i++) {

		father[i] = i;//��ʼ�����飨ע���Ǵ�1��ʼ�ģ�����ÿһ���ڵ�ĸ��ڵ���Ϊ�Լ�

	}

}



int find(int x) {//Ѱ�Ҹ��ڵ�

	while (x != father[x]) {

    	        x = father[x];

	}

	return x;

}



void add(int x, int y, int n) {//�ϲ�

	int findX = find(x);

	int findY = find(y);

	if (findX != findY) {

		father[findX] = findY;

	}

}



void count( int n) {

	int cnt = n - 1;

	for (int i = 1; i <= n; i++)

	{

    		if (father[i]!=i)

		{

			cnt--;

		}

	}

	cout << cnt << endl;

}



int main() {

	int m, n;

	int x, y;

	while (true) {

		cin >> n;

		if (n == 0) {

			break;

		}

		else {

			cin >> m;

			if (m == 0) {

				cout << n - 1 << endl;

				continue;

			}

			init(n);

			for (int i = 0; i < m; i++) {

				cin >> x >> y;

				add(x, y, n);

			}

			count(n);

		}

	}

	return 0;

}
