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

int n, k;
long long dp[5001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    fill(dp, dp + 5001, 98765432100);

    dp[1] = 0;

    vector<int> v(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    for (long long i = 2; i <= n; i++)
    {
        for (long long j = 1; j < i; j++)
        {
            long long power = (i - j) * (1 + abs(v[i] - v[j]));
            power = max(power, dp[j]);
            dp[i] = min(dp[i], power);
        }
    }

    cout << dp[n];
}
