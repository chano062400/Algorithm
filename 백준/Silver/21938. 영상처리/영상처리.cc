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
using namespace std;

int n, m, t, cnt = 0;
int R[1001][1001], G[1001][1001], B[1001][1001], RGB[1001][1001], res[1001][1001];
bool visited[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x,y });

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 1 || nx > n || ny <1 || ny > m || visited[nx][ny] || RGB[nx][ny] != 255) continue;

            q.push({ nx,ny });
            visited[nx][ny] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
            cin >> R[i][j] >> G[i][j] >> B[i][j];
		}
	}
    
    cin >> t;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if ((R[i][j] + G[i][j] + B[i][j]) / 3 < t) RGB[i][j] = 0;
            else RGB[i][j] = 255;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (RGB[i][j] == 255 && !visited[i][j])
            {
                bfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt;
}
