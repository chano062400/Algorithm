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

int n, m;
int dp[41] = {};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 1];
    }

    int prevnum = 0, res = 1;
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        if (prevnum == 0)
        {
            res *= dp[num - 1];
            prevnum = num;
        }
        else
        {
            res *= dp[num - prevnum - 1];
            prevnum = num;
        }
    }

    res *= dp[n - prevnum];

    cout << res;
}
