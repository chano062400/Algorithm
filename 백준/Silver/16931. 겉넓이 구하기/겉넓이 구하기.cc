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

int arr[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int res = n * m * 2;

    for (int y = 1; y <= m; y++)
    {
        // 상
        for (int x = 1; x <= n; x++)
        {
            if (x == 1)
            {
                res += arr[x][y];
            }
            else
            {
                res += max(0, arr[x][y] - arr[x - 1][y]);
            }
            
        }

        // 하
        for (int x = n; x >= 1; x--)
        {
            if (x == n)
            {
                res += arr[x][y];
            }
            else
            {
                res += max(0, arr[x][y] - arr[x + 1][y]);
            }
        }
    }

    for (int x = 1; x <= n; x++)
    {
        // 좌
        for (int y = 1; y <= m; y++)
        {
            if (y == 1)
            {
                res += arr[x][y];
            }
            else
            {
                res += max(0, arr[x][y] - arr[x][y - 1]);
            }
        }

        // 우
        for (int y = m; y >= 1; y--)
        {
            if (y == m)
            {
                res += arr[x][y];
            }
            else
            {
                res += max(0, arr[x][y] - arr[x][y + 1]);
            }
        }
    }

    cout << res;
}