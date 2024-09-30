#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stack>
#include <regex>
#include <map>
#include <cstdlib>
#include <list>
#include <sstream>
#include <bitset>
#include <set>
#include <unordered_map>
#include <numeric>
#include <memory>
using namespace std;

int r, c, k, row = 3, col = 3;
vector<vector<int>> v(101, vector<int>(101, 0));

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second < p2.second;
}

void calcrow(int colnum)
{
	for (int i = 1; i <= row; i++)
	{
		vector<pair<int, int>> temp;
		for (int j = 1; j <= colnum; j++)
		{
			if (v[i][j] == 0) continue;

			int idx = find_if(temp.begin(), temp.end(), [&i, &j](const pair<int, int> p) {return p.first == v[i][j]; }) - temp.begin();
			if (idx == temp.size()) temp.push_back({ v[i][j],1 });
			else temp[idx].second++;
		}
		sort(temp.begin(), temp.end(), cmp);
		
		fill(v[i].begin(), v[i].end(), 0);

		for (int idx = 0; idx < temp.size(); idx++)
		{
			v[i][idx * 2 + 1] = temp[idx].first;
			v[i][idx * 2 + 2] = temp[idx].second;
		}
		
		int size = temp.size();
		col = max(col,size * 2);
	}	 
}

void calccol(int rownum)
{
	for (int i = 1; i <= col; i++)
	{
		vector<pair<int, int>> temp;
		for (int j = 1; j <= rownum; j++)
		{
			if (v[j][i] == 0) continue;

			int idx = find_if(temp.begin(), temp.end(), [&i, &j](const pair<int, int> p) {return p.first == v[j][i]; }) - temp.begin();
			if (idx == temp.size()) temp.push_back({ v[j][i],1 });
			else temp[idx].second++;
		}
		sort(temp.begin(), temp.end(), cmp);
		
		for (int row = 1; row <= 100; row++)
		{
			v[row][i] = 0;
		}

		for (int idx = 0; idx < temp.size(); idx++)
		{
			v[idx * 2 + 1][i] = temp[idx].first;
			v[idx * 2 + 2][i] = temp[idx].second;
		}

		int size = temp.size();
		row = max(row, size * 2);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> v[i][j];
		}
	}

	int time = 0;
	while (1)
	{
		if (v[r][c] == k || time > 100) break;

		if (row >= 100) row = 100;
		if (col >= 100) col = 100;

		if (row >= col) calcrow(col);
		else calccol(row);
		time++;
	}
	
	time > 100 ? cout << -1 : cout << time;

}

