#include <iostream>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)

	{
		int cnt = 1;//����һ������
		int N;
		cin >> N;
		vector<int> P[50 + 1];
		P[1].push_back(1);
		for (int i = 2; i <= 1300; i++)
			//�ӵڶ�����ʼ��
		{
			int flag = 0;
			for (int j = 1; j <= cnt; j++)
				//�����е�����������
			{
				int sum = P[j].back()  +  i;
				if (int(sqrt(sum))*int(sqrt(sum)) == sum)
				{
					P[j].push_back(i);
					flag = 1;
					break;
				}
			}
			if (flag == 0 && cnt == N)
			{
				cout << --i << endl;
				break;
			}
			if (flag == 0 && cnt != N)
				P[++cnt].push_back(i);
		}
	}
	return 0;
}

