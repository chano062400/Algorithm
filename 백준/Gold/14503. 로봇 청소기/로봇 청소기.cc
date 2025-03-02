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

// 0 - 청소하지 않은 상태, 1 - 벽, 2 - 청소한 상태.
int arr[50][50], n, m, r, c, d, clean;
// 북 동 남 서
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void solve(int x, int y, int dir)
{
    int cx = x, cy = y, cdir = dir;
    while (1)
    {
        if (arr[cx][cy] == 0)
        {
            arr[cx][cy] = 2;
            clean++;
        }

        int cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (arr[nx][ny] != 0) continue;
            cnt++;
        }

        if (cnt == 0)
        {
            int nx = cx - dx[cdir];
            int ny = cy - dy[cdir];

            if (arr[nx][ny] == 1) break;
            // 한 칸 후진.
            cx = nx, cy = ny;
            continue;
        }
        else
        {
            // 반시계 방향으로 회전.
            cdir = (cdir + 3) % 4;
            int nx = cx + dx[cdir];
            int ny = cy + dy[cdir];

            if (arr[nx][ny] == 0)   
            {
                cx = nx, cy = ny;
                continue;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    cin >> r >> c >> d;

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    solve(r, c, d);

    cout << clean;
}