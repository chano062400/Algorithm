#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
using namespace std;

int w, h, k, res = -1;
int dx[] = { 1,-1,0,0}; 
int dy[] = { 0,0,1,-1};
int hx[] = { -2, -1, 1, 2, 2, 1, -1, -2 }; 
int hy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int v[200][200];
bool visited[200][200][31];

struct info 
{
    int x, y, k, cnt;
};

void bfs()
{
    queue<info> q;
    q.push({ 0, 0, k, 0});
    visited[0][0][k] = true;

    while (!q.empty())
    {
        int cx = q.front().x;
        int cy = q.front().y;
        int k = q.front().k;
        int cnt = q.front().cnt;
        q.pop();

        if (cx == h - 1 && cy == w - 1)
        {
            res = cnt;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (visited[nx][ny][k] || v[nx][ny] == 1) continue;
            visited[nx][ny][k] = true;
            q.push({ nx,ny,k,cnt + 1 });
        }

        if (k > 0)
        {
            for (int i = 0; i < 8; i++)
            {
                int nx = cx + hx[i];
                int ny = cy + hy[i];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (visited[nx][ny][k - 1] || v[nx][ny] == 1) continue;
                visited[nx][ny][k - 1] = true;
                q.push({ nx,ny,k - 1,cnt + 1 });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> w >> h;

    for (int i = 0; i < h; i++) 
    {
        for (int j = 0; j < w; j++) 
        {
            cin >> v[i][j];
        }
    }

    bfs();

    cout << res;
}
