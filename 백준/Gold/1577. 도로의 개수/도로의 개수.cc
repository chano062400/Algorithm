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
#include <bitset>
#include <set>
#include <unordered_map>
#include <numeric>
#include <memory>
using namespace std;

struct pos
{
    int x, y;
};

int n, m, k;
long long dp[101][101];
vector<pair<pos, pos>> v;

bool isblock(int x, int y, int x2, int y2)
{
    bool block = false;
    for (int i = 0; i < v.size(); i++)
    {
        if (x == v[i].first.x && y == v[i].first.y && x2 == v[i].second.x && y2 == v[i].second.y)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a > c || b > d)
        {
            v.push_back({ {c,d},{a,b} });
        }
        else
        {
            v.push_back({ {a,b},{c,d} });
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0)
            {
                if (!isblock(i, j - 1, i, j))
                {
                    dp[i][j] += dp[i][j - 1];
                }
                else continue;
            }
            else if (j == 0)
            {
                if (!isblock(i - 1, j, i, j))
                {
                    dp[i][j] += dp[i - 1][j];
                }
                else continue;
            }
            else
            {
                if (!isblock(i, j - 1, i, j))
                {
                    dp[i][j] += dp[i][j - 1];
                }
                if (!isblock(i - 1, j, i, j))
                {
                    dp[i][j] += dp[i - 1][j];
                }
            }
        }
    }

    cout << dp[n][m];

}
   