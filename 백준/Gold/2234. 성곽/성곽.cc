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
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
int area[51][51];
int arr[51][51];
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
            if (arr[cx][cy] & (1 << i)) continue;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
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
                if (arr[i][j] & (1 << k))
                {
                    int curroom = area[i][j], ni = i + dx[k], nj = j + dy[k];
                    if (ni < 1 || ni > m || nj < 1 || nj > n) continue;

                    int nextroom = area[ni][nj];
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