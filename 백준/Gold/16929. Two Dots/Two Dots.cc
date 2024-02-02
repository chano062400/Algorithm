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
using namespace std;

int n, m;
char arr[51][51];
bool visited[51][51], Iscycle = false;
int dx[] = { 1,-1,0,0, };
int dy[] = { 0,0,1,-1 };

void dfs(int sx, int sy, int cx, int cy, int depth)
{
    visited[cx][cy] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = cx + dx[i];
        int ny = cy + dy[i];

        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
        {
            if (depth > 1 && visited[nx][ny] && nx == sx && ny == sy) Iscycle =true;
            
            if (!visited[nx][ny] && arr[nx][ny] == arr[cx][cy])
            {
                dfs(sx, sy, nx, ny, depth + 1);
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dfs(i, j, i, j, 0);
            if(Iscycle) break;
            memset(visited, 0, sizeof(visited));
        }
    }

    if (Iscycle) cout << "Yes";
    else cout << "No";

};

