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
#include <set>
#include <unordered_map>
#include <numeric>
#include <memory>
using namespace std;

int n, m, x, y, arr[501][1001];
bool visited[501][1001];
int dist[501][1001];
int dx[] = { -2,-2,-1,-1,1,1,2,2 };
int dy[] = { -1,1,-2,2,-2,2,-1,1 };

void bfs(int x, int y)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({ {x,y},0 });
    visited[x][y] = true;

    while (!q.empty())
    {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int curdist = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            dist[nx][ny] = curdist + 1;
            q.push({ {nx,ny}, curdist + 1 });
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    cin >> x >> y;

    bfs(x, y);

    for (int i = 0; i < m; i++)
    {
        int tx, ty;
        cin >> tx >> ty;
        cout << dist[tx][ty] << '\n';
    }
}

