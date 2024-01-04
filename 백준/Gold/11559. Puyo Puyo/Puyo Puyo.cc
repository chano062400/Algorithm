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

char arr[12][6];
int res =0;
bool visited[12][6], findchain = false;;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void down()
{
    for(int j = 0; j < 6; j++)
    {
        for (int i = 11; i >= 0; i--)
        {
            if (arr[i][j] != '.') continue; // 맨 밑에서 부터 .를 찾음 (터진 곳)
            for (int h = 0; h <= i; h++)
            {
                if (arr[h][j] != '.') // 위에서부터 .가 아닌 내려가야 할 곳.
                {
                    char color = arr[i][j];
                    arr[i][j] = arr[h][j];
                    arr[h][j] = color;
                }
            }
        }
    }
}

void explosion(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = 0;
    char color = arr[x][y];
    arr[x][y] = '.';

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			char nc = arr[nx][ny];

			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6 || !visited[nx][ny] || nc != color) continue;

			arr[nx][ny] = '.';
			q.push({ nx,ny });
			visited[nx][ny] = 0;
		}
	}
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = 1;
    int cnt = 1;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        char cc = arr[cx][cy];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            char nc = arr[nx][ny];

            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6 || visited[nx][ny] || nc != cc) continue;

            cnt++;
            q.push({ nx,ny });
            visited[nx][ny] = 1;
        }
    }

    if (cnt >= 4)
    {
        findchain = true;
        explosion(x, y);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> arr[i][j];
        }
    }

    while (1)
    {
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (arr[i][j] != '.' && !visited[i][j])
                {
                    bfs(i, j);
                }
            }
        }
        if (findchain)
        {
            res++;
            down();
            memset(visited, 0, sizeof(visited));
            findchain = false;
        }
        else break;
    }

    cout << res;
}
