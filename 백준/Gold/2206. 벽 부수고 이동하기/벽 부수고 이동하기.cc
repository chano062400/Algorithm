#include<iostream>
#include<algorithm>
#include<queue>


using namespace std;

int a, b;
int arr[1000][1000];
bool visited[1000][1000][2];
queue<pair<pair<int, int>, pair<int,int>>> q;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

int bfs()
{	
	q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
	visited[0][0][0] = 1;

	while (!q.empty())
	{
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int wall = q.front().second.first;
		int dist = q.front().second.second;
		q.pop();

		if (cy == a - 1 && cx == b - 1)
			return dist;

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= 0 && nx >= 0 && ny < a && nx < b)
			{
				if (arr[ny][nx] == 1 && wall == 0) // 아직 부시지 않은 벽이라면 부순 후의 거리를 큐에 넣음
				{
					visited[ny][nx][wall + 1] =1;
					q.push(make_pair(make_pair(ny, nx), make_pair(wall + 1, dist + 1)));
				}
				else if (arr[ny][nx] == 0 && !visited[ny][nx][wall]) // 벽이 없고 간 적 없다면
				{
					visited[ny][nx][wall] = 1;
					q.push(make_pair(make_pair(ny, nx), make_pair(wall, dist + 1)));
				}
			}
		}

	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b;
	for (int i = 0; i < a; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < b; j++)
		{
			arr[i][j] = str[j] - '0';
		}
	}

	cout << bfs() <<'\n';


}
	