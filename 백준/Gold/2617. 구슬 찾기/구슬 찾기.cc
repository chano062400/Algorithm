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

bool isheavy[100][100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, res = 0;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        isheavy[a][b] = true;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (isheavy[i][k] && isheavy[k][j])
                {
                    isheavy[i][j] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int lower = 0, higher = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;

            if (isheavy[i][j]) higher++;
            else if (isheavy[j][i]) lower++;
        }
        if (lower > n / 2 || higher > n / 2)
        {
            res++;
        }
    }

    cout << res;
}