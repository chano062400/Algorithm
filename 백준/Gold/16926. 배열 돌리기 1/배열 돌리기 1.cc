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

void rotate(int sx, int sy, int ex, int ey, const vector<vector<int>>& v, vector<vector<int>>& temp)
{
    // 왼쪽
    for (int i = ey; i > sy; i--)
    {
        temp[sx][i - 1] = v[sx][i];
    }

    // 아래
    for (int i = sx; i < ex; i++)
    {
        temp[i + 1][sy] = v[i][sy];
    }

    // 오른쪽
    for (int i = sy; i < ey; i++)
    {
        temp[ex][i + 1] = v[ex][i];
    }

    // 위
    for (int i = ex; i > sx; i--)
    {
        temp[i - 1][ey] = v[i][ey];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<int>> v(n + 1, vector<int>(m + 1, 0)), temp;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> v[i][j];
        }
    }

    temp = v;

    while (r--)
    {
        int sx = 1, sy = 1, ex = n, ey = m;
        while (sx <= min(n,m) / 2)
        {
            rotate(sx, sy, ex, ey, v, temp);
            sx++;
            ex--;
            sy++;
            ey--;
        }
        v = temp;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
    
}

