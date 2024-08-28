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

#define MAX 1000000007
int n, m, dp[10001], res = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (i >= m)
        {
            dp[i] = (dp[i - 1] + dp[i - m]) % MAX;
        }
        else
        {
            dp[i] = 1;
        }
    }

    cout << dp[n];
}

