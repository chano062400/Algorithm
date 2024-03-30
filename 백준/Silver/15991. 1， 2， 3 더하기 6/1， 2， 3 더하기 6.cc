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

int t,n;
long long dp[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> t;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    dp[4] = 3;
    dp[5] = 3;
    dp[6] = 6;
    
    for (int i = 7; i <= 100000; i++)
    {
        dp[i] = ((dp[i - 2] + dp[i - 4]) % 1000000009 + dp[i - 6]) % 1000000009;
    }

    while (t--)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }
}
