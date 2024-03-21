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

int l, r, c, res = 0;
char arr[31][31][31];
bool visited[31][31][31];
int dx[] = {0,0,1,-1,0,0};
int dy[] = {0,0,0,0,1,-1};
int df[] = {1,-1,0,0,0,0 };

struct Info
{
    int cnt = 0, floor = 0, x = 0, y = 0;
};

bool bfs(int f, int x, int y)
{
    queue<Info>q;
    q.push({ 0,f,x,y });
    visited[f][x][y] = true;

    while (!q.empty())
    {
        int curcnt = q.front().cnt;
        int cf = q.front().floor;
        int cx = q.front().x;
        int cy = q.front().y;
        q.pop();

        if (arr[cf][cx][cy] == 'E')
        {
            res = curcnt;
            return true;
        }

        for (int i = 0; i < 6; i++)
        {
            int nf = cf + df[i];
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nf >= 1 && nf <= l && nx >= 1 && nx <= r && ny >= 1 && ny <= c)
            {
                if (!visited[nf][nx][ny] && arr[nf][nx][ny] != '#')
                {
                    q.push({ curcnt + 1, nf, nx, ny });
                    visited[nf][nx][ny] = 1;
                }
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while (1)
    {
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0) break;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        res = 0;
        int sf = 0, sx = 0, sy = 0;
        for (int i = 1; i <= l; i++)
        {
            for (int x = 1; x <= r; x++)
            {
                for (int y = 1; y <= c; y++)
                {
                    cin >> arr[i][x][y];
                    if (arr[i][x][y] == 'S')
                    {
                        sf = i;
                        sx = x;
                        sy = y;
                    }
                }
            }
        }
        if (bfs(sf, sx, sy)) cout << "Escaped in " << res << " minute(s)." << '\n';
        else cout << "Trapped!" << '\n';;
    }
}
