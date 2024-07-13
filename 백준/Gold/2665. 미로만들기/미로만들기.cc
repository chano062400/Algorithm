#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int n, cnt;
int arr[51][51], dist[51][51];
bool visited[50][50];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

void dijkstr(int wall, int y, int x)
{
	dist[0][0] = 0;
	visited[y][x] = 1;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
	pq.push(make_pair(wall,make_pair(y,x)));

	while (!pq.empty())
	{
		int cy = pq.top().second.first;
		int cx = pq.top().second.second;
		int wcnt = dist[cy][cx];
		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= 0 && ny < n && nx >= 0 && nx < n)
			{
				if (arr[ny][nx] == 1)
				{
					if (dist[cy][cx] < dist[ny][nx])
					{
						dist[ny][nx] = dist[cy][cx];
                        pq.push(make_pair(dist[ny][nx],make_pair(ny, nx)));
					}
				}
				else if(arr[ny][nx] == 0)
				{
					if (dist[cy][cx] + 1 < dist[ny][nx])
					{
						dist[ny][nx] = dist[cy][cx] + 1;
                        pq.push(make_pair(dist[ny][nx], make_pair(ny, nx)));
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = str[j] - '0';
			dist[i][j] = 10000;
		}
	}

	memset(visited, 0, sizeof(visited));


	dijkstr(0,0,0);

	cout << dist[n-1][n-1];

	return 0;
}