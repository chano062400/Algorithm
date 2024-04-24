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

int n, m, fx = 0, fy = 0, sx = 0, sy = 0;
char arr[21][21];
bool visited[21][21][21][21];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

struct Info
{
    int cnt,x, y, ox, oy;
};

int bfs(int x, int y, int ox, int oy)
{
    queue<Info> q;
    q.push({0,x,y,ox,oy});
    visited[x][y][ox][oy] = 1;

    while (!q.empty())
    {
        int curcnt = q.front().cnt;
        int cx = q.front().x;
        int cy = q.front().y;
        int cox = q.front().ox;
        int coy = q.front().oy;
        q.pop();

        visited[cx][cy][cox][coy] = 1;
        if (curcnt >= 10) return -1;

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
			int nox = cox + dx[i];
			int noy = coy + dy[i];

			if (!visited[nx][ny][nox][noy])
			{
				if (arr[nx][ny] == '#' && arr[nox][noy] == '#') continue;
				if ((nx == cox && ny == coy && arr[nox][noy] == '#') || (nox == cx && noy == cy && arr[nx][ny] == '#')) continue;
				if ((nx < 1 || nx > n || ny < 1 || ny > m) && (nox < 1 || nox > n || noy < 1 || noy > m)) continue;
				if ((nx < 1 || nx > n || ny < 1 || ny > m) || (nox < 1 || nox > n || noy < 1 || noy > m)) return curcnt + 1;

				if (arr[nx][ny] == '#')
				{
					q.push({ curcnt + 1,cx,cy,nox,noy });
				}
				else if (arr[nox][noy] == '#')
				{
					q.push({ curcnt + 1,nx,ny,cox,coy });
				}
				else
				{
					q.push({ curcnt + 1, nx,ny,nox,noy });
				}
			}
        }
    }

    return 11;
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
            if (arr[i][j] == 'o')
            {
                if (fx == 0 && fy == 0)
                {
                    fx = i;
                    fy = j;
                }
                else
                {
                    sx = i;
                    sy = j;
                }
            }
            
        }
    }

    int res = bfs(fx,fy,sx,sy);
    if (res > 10) cout << -1;
    else cout << res;
}
    