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

int arr[1001][1001], n, m, k;
// 0 안부심, 1 부심.
bool visited[1001][1001][11];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int bfs()
{
    queue<pair<pair<int, int>,pair<int,int>>> q;
    q.push({{1, 1}, {k, 1}});
    visited[1][1][0] = true;

    while (!q.empty())
    {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int ck = q.front().second.first;
        int cd = q.front().second.second;
        q.pop();

        if (cx == n && cy == m)
        {
            return cd;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;

            if (arr[nx][ny] == 0)
            {
                if (visited[nx][ny][ck]) continue;
                visited[nx][ny][ck] = true;
                q.push({{ nx,ny }, {ck, cd + 1}});
            }
            else
            {
                if (ck > 0)
                {
                    if (visited[nx][ny][ck]) continue;
                    visited[nx][ny][ck] = true;
                    q.push({{ nx,ny }, {ck - 1, cd + 1}});
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++)
        {
            arr[i][j] = str[j - 1] - '0';
        }
    }

    cout << bfs();
}