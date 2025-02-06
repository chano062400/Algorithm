#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "memory.h"
#include <set>
#include <unordered_set>
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

int n, m, r, arr[101][101], temp[101][101];

void copy()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            temp[i][j] = arr[i][j];
        }
    }
}

void solve(int op)
{
    copy();

    // 상하 반전
    if (op == 1)
    {
        for (int i = 1; i <= n / 2; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                swap(arr[i][j], arr[n - i + 1][j]);
            }
        }
    }
    // 좌우 반전
    else if (op == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m / 2; j++)
            {
                swap(arr[i][j], arr[i][m - j + 1]);
            }
        }
    }
    // 오른쪽으로 90도 회전
    else if (op == 3)
    {
        swap(n, m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                arr[i][j] = temp[m - j + 1][i];
            }
        }
    }
    // 왼쪽으로 90도 회전
    else if (op == 4)
    {
        swap(n, m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                arr[i][j] = temp[j][n - i + 1];
            }
        }
    }
    // 1 -> 2 2 -> 3 3 -> 4 4 -> 1
    else if (op == 5)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // 1번 그룹
                if (i <= n / 2 && j <= m / 2)
                {
                    arr[i][j] = temp[i + n / 2][j];
                }
                // 2번 그룹
                else if(i <= n / 2 && j > m / 2)
                {
                    arr[i][j] = temp[i][j - m / 2];
                }
                // 3번 그룹
                else if (i > n / 2 && j > m / 2)
                {
                    arr[i][j] = temp[i - n / 2][j];
                }
                // 4번 그룹
                else
                {
                    arr[i][j] = temp[i][j + m / 2];
                }
            }
        }
    }
    // 1 -> 4 4 -> 3 3 -> 2 2 -> 1
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // 1번 그룹
                if (i <= n / 2 && j <= m / 2)
                {
                    arr[i][j] = temp[i][j + m / 2];
                }
                // 2번 그룹
                else if (i <= n / 2 && j > m / 2)
                {
                    arr[i][j] = temp[i + n / 2][j];
                }
                // 3번 그룹
                else if (i > n / 2 && j > m / 2)
                {
                    arr[i][j] = temp[i][j - m / 2];
                }
                // 4번 그룹
                else
                {
                    arr[i][j] = temp[i - n / 2][j];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    while (r--)
    {
        int op;
        cin >> op;
        solve(op);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}