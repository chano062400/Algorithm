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

int n, m, k, arr[2001][2001], sumB[2001][2001], sumW[2001][2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++)
        {
            char ch = str[j - 1];
    
            int mapb = 0, mapw = 0;
            if ((i + j) % 2 == 0)
            {
                if (ch == 'B') mapw = 1;
                else mapb = 1;
            }
            else
            {
                if (ch == 'B') mapb = 1;
                else mapw = 1;
            }

            sumB[i][j] = sumB[i - 1][j] + sumB[i][j - 1] - sumB[i - 1][j - 1] + mapb;
            sumW[i][j] = sumW[i - 1][j] + sumW[i][j - 1] - sumW[i - 1][j - 1] + mapw;
        }
    }

    int res = n * m;
    for (int i = k; i <= n; i++)
    {
        for (int j = k; j <= m; j++)
        {
            int B = sumB[i][j] - sumB[i - k][j] - sumB[i][j - k] + sumB[i - k][j - k];
            int W = sumW[i][j] - sumW[i - k][j] - sumW[i][j - k] + sumW[i - k][j - k];
            res = min(res, min(B, W));
        }
    }

    cout << res;
}