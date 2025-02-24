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

int n, m, v, k;
char arr[251][251];
bool visited[251][251];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;
    
    int vcnt = 0, kcnt = 0;
    if (arr[x][y] == 'v') vcnt++;
    if (arr[x][y] == 'k') kcnt++;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m)continue;
            if (visited[nx][ny] || arr[nx][ny] == '#') continue;
            if (arr[nx][ny] == 'v') vcnt++;
            if (arr[nx][ny] == 'k') kcnt++;
            visited[nx][ny] = true;
            q.push({ nx,ny });
        }
    }

    if(kcnt > vcnt) k += kcnt;
    else v += vcnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++)
        {
            arr[i][j] = str[j - 1];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!visited[i][j] && arr[i][j] != '#')
            {
                bfs(i, j);
            }
        }
    }


    cout << k << " " << v;
}