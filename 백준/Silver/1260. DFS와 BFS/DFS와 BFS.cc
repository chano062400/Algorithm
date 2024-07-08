#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int a, b, c;
int arr[1001][1001];
bool visited[1001];

void reset()
{
	for (int i = 1; i <= a; i++)
	{
		visited[i] = false;
	}
}

void dfs(int idx)
{
	visited[idx] = true;
	cout << idx << " ";

	for (int i = 1; i <= a; i++)
	{
		if (!visited[i] && arr[idx][i] == 1)
		{
			dfs(i);
		}
	}
}

void bfs(int idx)
{
	queue<int> q;
	q.push(idx);

	while (!q.empty())
	{
		int cur = q.front();
		visited[cur] = 1;
		cout << cur << " ";
		q.pop();
		

		for (int i = 1; i <= a; i++)
		{
			if (!visited[i] && arr[cur][i] ==1)
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;
	for (int i = 0; i < b; i++)
	{
		int x, y;
		cin >> y >> x;
		arr[y][x] = 1;
		arr[x][y] = 1;
	}

	dfs(c);
	cout << '\n';

	reset();
	bfs(c);
}
	