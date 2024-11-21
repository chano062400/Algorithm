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

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int arr[101][101];

bool check(int y, int x)
{
    if (y + 1 >= 101 || x + 1 >= 101) return false;
    
    if (arr[y][x] == 1 && arr[y + 1][x] == 1 && arr[y][x + 1] == 1 && arr[y + 1][x + 1] == 1) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        arr[y][x] = 1;
        y += dy[d];
        x += dx[d];
        v.push_back(d);
        arr[y][x] = 1;

        while (g--)
        {
            int idx = v.size() - 1;
            for (int i = idx; i >= 0; i--)
            {
                int dir = (v[i] + 1) % 4;
                x += dx[dir];
                y += dy[dir];
                v.push_back(dir);
                arr[y][x] = 1;
            }
        }
    }
    
    int res = 0;
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            if (check(i, j))
            {
                res++;
            }
        }
    }
    cout << res;
}
