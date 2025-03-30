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

int n, k, s, arr[401][401];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }

    for (int h = 1; h <= n; h++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j) continue;
                if (arr[i][h] && arr[h][j])
                {
                    arr[i][j] = 1;
                }
            }
        }
    }

    cin >> s;
    for (int i = 0; i < s; i++)
    {
        int a, b;
        cin >> a >> b;
        if(arr[a][b] && !arr[b][a])
        {
            cout << -1 << '\n';
        }
        else if(arr[b][a] && !arr[a][b])
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
}