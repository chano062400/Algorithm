#include <iostream>
#include <vector>
#include <algorithm>;
#include <set>;
using namespace std;

int c, p;
int arr[101][101];

vector<vector<string>> shapes(8, vector<string>());
vector<int> res(8, 0);
vector<int> heights(101);

void solve(int column, int shape)
{
	for (int i = 0; i < shapes[shape].size(); i++)
	{
		int len = shapes[shape][i].length();
		set<int> s;
		int idx = 0;
		bool flag = true;

		for (int j = column; j < column + len; j++)
		{
			if (j > c)
			{
				flag = false;
				break;
			}
			s.insert(heights[j] - (shapes[shape][i][idx++] - '0'));
		}
		if (!flag) continue;
		if (s.size() == 1) res[shape]++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> c >> p;

	// 모양 별 바닥과 떨어진 높이 차이.
	shapes[1].push_back("0");
	shapes[1].push_back("0000");

	shapes[2].push_back("00");

	shapes[3].push_back("001");
	shapes[3].push_back("10");

	shapes[4].push_back("100");
	shapes[4].push_back("01");

	shapes[5].push_back("000");
	shapes[5].push_back("01");
	shapes[5].push_back("101");
	shapes[5].push_back("10");

	shapes[6].push_back("000");
	shapes[6].push_back("00");
	shapes[6].push_back("011");
	shapes[6].push_back("20");

	shapes[7].push_back("000");
	shapes[7].push_back("02");
	shapes[7].push_back("110");
	shapes[7].push_back("00");

	for (int i = 1; i <= c; i++)
	{
		cin >> heights[i];
	}

	for (int i = 1; i <= c; i++)
	{
		for (int j = 1; j <= 7; j++)
		{
			solve(i, j);
		}
	}

	cout << res[p];
}