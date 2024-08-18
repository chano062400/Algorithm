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

int n, m;
int arr[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool visited[1001][1001];

bool canmove(pair<int, int> nlt, pair<int, int> nrt, pair<int, int> nlb, pair<int, int> nrb)
{
    // 위쪽 직선 
    for (int i = nlt.first; i <= nrt.first; i++)
    {
        if (arr[i][nlt.second] == 1) return false;
    }

    // 아래쪽 직선
    for (int i = nlb.first; i <= nrb.first; i++)
    {
        if (arr[i][nlb.second] == 1) return false;
    }

    // 왼쪽 직선
    for (int i = nlt.second; i <= nlb.second; i++)
    {
        if (arr[nlt.first][i] == 1) return false;
    }

    // 오른쪽 직선
    for (int i = nrt.second; i <= nrb.second; i++)
    {
        if (arr[nrt.first][i] == 1) return false;
    }

    return true;
}

int bfs(int h, int w, int x, int y, int tx, int ty)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({ { x, y },0 });
    visited[x][y] = true;

    while (!q.empty())
    {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        if (cx == tx && cy == ty) return dist;

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            pair<int, int> nlt = { nx,ny };
            pair<int, int> nrt = { nx + h , ny };
            pair<int, int> nlb = { nx, ny + w };
            pair<int, int> nrb = { nx + h, ny + w };

            if (nx < 1 || nx > n || ny < 1 || ny > m || nx + h > n || ny + w > m) continue;
            if (visited[nx][ny]) continue;
            if (arr[nlt.first][nlt.second] == 1 || arr[nrt.first][nrt.second] == 1 ||
                arr[nlb.first][nlb.second] == 1 || arr[nrb.first][nrb.second] == 1) continue;
            if (!canmove(nlt, nrt, nlb, nrb)) continue;

            q.push({ {nx,ny},dist + 1 });
            visited[nx][ny] = true;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int h, w, sx, sy, ex, ey;
    cin >> h >> w >> sx >> sy >> ex >> ey;
    if (sx < 1 || sx > n - h + 1 || sy < 1 || sy > m - w + 1 || ex < 1 || ex > n - h + 1 || ey < 1 || ey > m - w + 1)
    {
        cout << -1;
        return 0;
    }

    cout << bfs(h - 1, w - 1, sx, sy, ex, ey);

}
