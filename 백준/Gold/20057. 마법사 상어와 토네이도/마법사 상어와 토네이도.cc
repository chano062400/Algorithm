#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "memory.h"
#include <set>
#include <unordered_set>
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

// 좌 하 우 상 순서
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
int arr[505][505], x , y, n, res;
int ddx[4][9] = {
    { 0, -1, 1,  -2, 2, -1, 1, -1, 1 },
    { 2, 1, 1, 0, 0, 0, 0, -1, -1 },
    { 0, 1, -1,  2, -2, 1, -1, 1, -1 },
    { -2, -1, -1,  0, 0, 0, 0, 1, 1 }
};

int ddy[4][9] = {
    { -2, -1, -1, 0, 0, 0, 0, 1, 1 },
    { 0, -1, 1, -2, 2, -1, 1, -1, 1 },
    { 2, 1, 1, 0, 0, 0, 0, -1, -1 },
    { 0, -1, 1, -2, 2, -1, 1, -1, 1 }
};
int percent[9] = { 5,10,10,2,2,7,7,1,1 };

void spread(int sand, int nx, int ny, int ratio, int& sum)
{
    int movesand = sand * ratio / 100;

    // 격자 밖으로 나간 모래
    if (nx < 1 || nx > n || ny < 1 || ny > n) res += movesand;
    else
    {
        arr[nx][ny] += movesand;
    }
    sum += movesand;
}

void calc(int x, int y, int dir)
{
    int nx, ny;
    int sand = arr[x][y];

    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        nx = x + ddx[dir][i];
        ny = y + ddy[dir][i];

        spread(sand, nx, ny, percent[i], sum);
    }
    
    // 퍼지고 남은 모래 이동.
    arr[x][y] = 0;
    nx = x + dx[dir], ny = y + dy[dir];
    if (nx < 1 || nx > n || ny< 1 || ny> n) res += sand - sum;
    else arr[nx][ny] += sand - sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    x = ceil(double(n) / double(2));
    y = ceil(double(n) / double(2));

    int cnt = 1, dir = 0;
    while (1)
    {
        int loop = 2;
        while (loop--)
        {
            int movecnt = cnt;
            while (movecnt--)
            {
                if (x == 1 && y == 1)
                {
                    cout << res;
                    return 0;
                }

                // 다음 이동 좌표.
                int nx = x += dx[dir];
                int ny = y += dy[dir];

                calc(nx, ny, dir);

                x = nx, y = ny;
            }
            dir = (dir + 1) % 4;
        }
        cnt++;
    }
}