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

int n, m, arr[51][101];
int dx[] = { 0,0,-1,-1,-1,0,1,1,1 };
int dy[] = { 0,-1,-1,0,1,1,1,0,-1 };
bool check[51][101];
vector<pair<int, int>> cloud;

void cloudmove(int d, int s)
{
	for (int i = 0; i < cloud.size(); i++)
	{
		int nx = cloud[i].first + dx[d] * s;
		int ny = cloud[i].second + dy[d] * s;

		while (nx < 0) nx = n + nx;
		while (ny < 0) ny = n + ny;
		while (nx > n) nx %= n;
		while (ny > n) ny %= n;
		
		if (nx == 0) nx = n;
		if (ny == 0) ny = n;

		arr[nx][ny] += 1;
		cloud[i] ={ nx,ny };
		check[nx][ny] = 1;
	}
	sort(cloud.begin(), cloud.end());
}

void copywater()
{
	for (int i = 0; i < cloud.size(); i++)
	{
		int cnt = 0;
		int cx = cloud[i].first;
		int cy = cloud[i].second;

		for (int j = 2; j <= 8; j+=2)
		{
			int nx = cx + dx[j];
			int ny = cy + dy[j];
			
			if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
			if (arr[nx][ny] <= 0) continue;

			cnt++;
		}

		arr[cx][cy] += cnt;
	}
	cloud.clear();
}

void createcloud()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] >= 2 && !check[i][j])
			{
				cloud.push_back({ i,j });
				arr[i][j] -= 2;
			}
		}
	}
	sort(cloud.begin(), cloud.end());
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}

	cloud.push_back({ n - 1,1 });
	cloud.push_back({ n - 1,2 });
	cloud.push_back({ n,1 });
	cloud.push_back({ n,2 });

	for (int i = 0; i < m; i++)
	{
		int d, s;
		cin >> d >> s;
		
		cloudmove(d, s);

		copywater();
		
		createcloud();

		memset(check, 0, sizeof(check));
	}

	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			sum += arr[i][j];
		}
	}

	cout << sum;
}

