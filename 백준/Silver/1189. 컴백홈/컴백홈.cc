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
using namespace std;

int r, c, k, res =0;
int arr[6][6], dist[6][6];
bool visited[6][6];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y, int dist)
{
    if (dist > k) return;

    if (x == 1 && y == c && dist == k)
    {
        res++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 1 && nx <= r && ny >= 1 && ny <= c && arr[nx][ny] != 'T' && !visited[nx][ny])
        {
            visited[nx][ny] = 1;
            dfs(nx, ny, dist + 1);
            visited[nx][ny] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> r >> c >> k;
    for (int i = 1; i <= r; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= c; j++)
        {
            arr[i][j] = str[j-1];
        }
    }

    visited[r][1] = 1;
    dfs(r,1,1);

    cout << res;
}
