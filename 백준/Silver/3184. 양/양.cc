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

int r, c, sheep = 0, wolf = 0, tmps =0, tmpw = 0;
char arr[251][251];
bool visited[251][251];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y)
{
    visited[x][y] = 1;
    if (arr[x][y] == 'o') tmps++;
    if (arr[x][y] == 'v') tmpw++;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 1 && nx <= r && ny >= 1 && ny <= c && arr[nx][ny] != '#' && !visited[nx][ny])
        {
            dfs(nx, ny);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= c; j++)
        {
            arr[i][j] = str[j - 1];
        }
    }

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (!visited[i][j] && (arr[i][j] == 'v' || arr[i][j] == 'o'))
            {
                dfs(i, j);
                if (tmps > tmpw) sheep += tmps;
                else wolf += tmpw;

                tmps = 0;
                tmpw = 0;
            }
        }
    }

    cout << sheep << " " << wolf;
};

