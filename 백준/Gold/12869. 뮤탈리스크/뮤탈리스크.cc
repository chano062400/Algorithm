#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stack>
#include <regex>
#include <map>
#include <cstdlib>
#include <list>
#include <sstream>
using namespace std;

int health[3] = { 0, };
int order[6][3] = { {9,3,1}, {9,1,3}, {3,9,1}, {3,1,9}, {1,9,3}, {1,3,9} };
int dp[61][61][61];

int dfs(int x, int y, int z)
{
    if (x == 0 && y == 0 && z == 0) return 0;

    if (x < 0) return dfs(0, y, z);
    if (y < 0) return dfs(x, 0, z);
    if (z < 0) return dfs(x, y, 0);

    if (dp[x][y][z] != -1) return  dp[x][y][z];
    dp[x][y][z] = 987654321;

    for (int i = 0; i < 6; i++)
    {
        dp[x][y][z] = min(dp[x][y][z], dfs(x - order[i][0], y - order[i][1], z - order[i][2]) + 1);
    }

    return dp[x][y][z];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    

    for (int i = 0; i < n; i++)
    {
        cin >> health[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << dfs(health[0], health[1], health[2]);
}
