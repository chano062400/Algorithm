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

int arr[501][501], n, m, a, b, k;
bool visited[501][501];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int bfs(int sx, int sy, int elbx, int elby, int ertx, int erty)
{
    queue<pair<int, int>> q;
    q.push({ sx,sy });
    visited[sx][sy] = true;

    while (!q.empty())
    {
        int crtx = q.front().first;
        int crty = q.front().second;
        int clbx = crtx + a - 1;
        int clby = crty - b + 1;
        q.pop();

        if (crtx == ertx && crty == erty && clbx == elbx && clby == elby)
        {
            return arr[crtx][crty];
        }

        for (int i = 0; i < 4; i++)
        {
            int nrtx = crtx + dx[i];
            int nrty = crty + dy[i];
            int nlbx = clbx + dx[i];
            int nlby = clby + dy[i];
            bool flag = true;
            if (nrtx < 1 || nrtx > n || nrty < 1 || nrty > m || nlbx < 1 || nlbx > n || nlby < 1 || nlby > m) continue;
            if (visited[nrtx][nrty]) continue;
            for (int x = nrtx; x <= nlbx; x++)
            {
                for (int y = nlby; y <= nrty; y++)
                {
                    if (arr[x][y] == -1)
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (!flag) continue;
            
            visited[nrtx][nrty] = true;
            arr[nrtx][nrty] = arr[crtx][crty] + 1;
            q.push({ nrtx,nrty });
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> a >> b >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = -1;
    }

    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    int srtx = x1, srty = y1 + b - 1, slbx = x1 + a - 1, slby = y1;
    int ertx = x2, erty = y2 + b - 1, elbx = x2 + a - 1, elby = y2;

    cout << bfs(srtx, srty, elbx, elby, ertx, erty);

}