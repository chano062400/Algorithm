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

int n, m, sx, sy, res = 0;
char arr[601][601];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool visited[601][601];

void bfs()
{
    queue<pair<int, int>> q;
    q.push({ sx,sy });
    visited[sx][sy] = 1;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && arr[nx][ny] != 'X')
            {
                if (arr[nx][ny] == 'P') res++;
                q.push({ nx,ny });
                visited[nx][ny] = 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'I')
            {
                sx = i;
                sy = j;
            }
        }
    }

    bfs();

    if (res == 0) cout << "TT";
    else cout << res;
}
    