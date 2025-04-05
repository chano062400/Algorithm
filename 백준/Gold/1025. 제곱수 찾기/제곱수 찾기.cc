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

int arr[9][9], n, m;
long long res = -1;

bool isSquare(long long x) {
    if (x < 0) return false;
    long long r = (long long)sqrt(x);
    return r * r == x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) 
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) 
        {
            arr[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            // 단일 칸
            if (isSquare(arr[i][j])) 
            {
                res = max(res, (long long)arr[i][j]);
            }
            // 가능한 이동 범위.
            for (int dx = -n + 1; dx < n; dx++) 
            {
                for (int dy = -m + 1; dy < m; dy++) 
                {
                    if (dx == 0 && dy == 0) continue;
                    long long num = 0;
                    int x = i, y = j;

                    while (x >= 0 && x < n && y >= 0 && y < m) 
                    {
                        num = num * 10 + arr[x][y];
                        if (isSquare(num)) 
                        {
                            res = max(res, num);
                        }
                        x += dx;
                        y += dy;
                    }
                }
            }
        }
    }

    cout << res;
    return 0;
}