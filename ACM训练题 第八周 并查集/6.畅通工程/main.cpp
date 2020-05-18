
#include<iostream>

#include<vector>



using namespace std;



//这个是一个用到并查集的问题



int father[10000];//定义一个数组



void init(int n) {

	for (int i = 1; i <= n; i++) {

		father[i] = i;//初始化数组（注意是从1开始的），将每一个节点的根节点设为自己

	}

}



int find(int x) {//寻找根节点

	while (x != father[x]) {

    	        x = father[x];

	}

	return x;

}



void add(int x, int y, int n) {//合并

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
