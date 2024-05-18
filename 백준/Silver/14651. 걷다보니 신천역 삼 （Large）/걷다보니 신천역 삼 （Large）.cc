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

int n;
long long dp[33334];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n;

    dp[1] = 0;
    dp[2] = 2;
    dp[3] = 6;

    for (int i = 4; i <= n; i++)
    {
        dp[i] = (dp[i - 1] * 3) % 1000000009;
    }

    cout << dp[n];
}
  