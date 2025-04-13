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

double dir[4];
int N, e, w, s, n, total, simple;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool visited[31][31];

double back(int cnt, int x, int y)
{
    if (cnt == N)
    {
        return 1.0;
    }

    double possibility = 0.0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!visited[nx][ny])
        {
            visited[nx][ny] = true;
            possibility += dir[i] * back(cnt + 1, nx, ny);
            visited[nx][ny] = false;
        }
    }
    return possibility;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> e >> w >> s >> n;
    dir[0] = e / 100.0;
    dir[1] = w / 100.0;
    dir[2] = s / 100.0;
    dir[3] = n / 100.0;

    visited[15][15] = true;
    
    cout.precision(10);
    cout << fixed << back(0, 15, 15);
}