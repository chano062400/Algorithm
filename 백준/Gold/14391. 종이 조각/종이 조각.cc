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

int n, m, res = 0;
int arr[5][5];
bool isrow[5][5];

void dfs(int x, int y) 
{
    if (y == m + 1)
    {
        dfs(x + 1, 1);
        return;
    }

    if (x == n + 1)
    {
        int temp = 0;

        // 가로 계산
        for (int r = 1; r <= n; r++)
        {
            int sum = 0;
            for (int c = 1; c <= m; c++)
            {
                // 가로
                if (isrow[r][c])
                {
                    sum = (sum * 10) + arr[r][c];
                }
                // 세로
                else
                {
                    temp += sum;
                    sum = 0;
                }
            }
            temp += sum;
        }

        // 세로 계산
        for (int c = 1; c <= m; c++)
        {
            int sum = 0;
            for (int r = 1; r <= n; r++)
            {
                if (!isrow[r][c])
                {
                    sum = (sum * 10) + arr[r][c];
                }
                else
                {
                    temp += sum;
                    sum = 0;
                }
            }
            temp += sum;
        }
        res = max(res, temp);
        return;
    }

    isrow[x][y] = true;
    dfs(x, y + 1);

    isrow[x][y] = false;
    dfs(x, y + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++)
        {
            arr[i][j] = str[j - 1] - '0';
        }
    }

    dfs(1, 1);
    cout << res;
}
