 #include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
#include <limits.h>
#include <list>
using namespace std;

int n, m, cnt = 0, maxextent = 0, maxremovewallextent = 0;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int area[51][51];
bool arr[51][51][4];
bool visited[51][51];
map<int, int> roomextent;

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;
    area[x][y] = cnt;

    int sum = 1;
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
            if (arr[cx][cy][i]) continue;
			if (visited[nx][ny]) continue;

			visited[nx][ny] = true;
			area[nx][ny] = area[cx][cy];
            sum++;
			q.push({ nx,ny });
        }
    }

    roomextent[cnt] = sum;
    maxextent = max(maxextent, sum);
}

int getnextroom(int x, int y, int dir)
{
    if (dir == 0)
    {
        return area[x + 1][y];
    }
    else if (dir == 1)
    {
        return area[x - 1][y];
    }
    else if (dir == 2)
    {
        return area[x][y + 1];
    }
    else
    {
        return area[x][y - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int num;
            cin >> num;
            while (num > 0)
            {
                if (num >= 8)
                {
                    num -= 8;
                    arr[i][j][0] = true;
                }
                else if (num >= 4)
                {
                    num -= 4;
                    arr[i][j][2] = true;
                }
                else if (num >= 2)
                {
                    num -= 2;
                    arr[i][j][1] = true;
                }
                else
                {
                    num -= 1;
                    arr[i][j][3] = true;
                }
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!visited[i][j])
            {
                ++cnt;
                bfs(i, j);
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (arr[i][j][k])
                {
                    int curroom = area[i][j], nextroom = getnextroom(i, j, k);
					// 벽을 제거했을 때 다음 방이 현재 방과 다르다면 넓이를 더함.
					if (curroom != nextroom)
					{
						maxremovewallextent = max(maxremovewallextent, roomextent[curroom] + roomextent[nextroom]);
					}
                }
            }
        }
    }

    cout << cnt << '\n';
    cout << maxextent << '\n';
    cout << maxremovewallextent << '\n';
}