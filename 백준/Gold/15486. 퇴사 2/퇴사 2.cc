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
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, res = 0, mx = 0;
    cin >> n;

    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int t, c;
        cin >> t >> c;
        // i일차까지 벌어들인 최대 수익.
        mx = max(mx, dp[i]);

        // n일까지 일한 돈은 n+1일차에 받는데, 0부터 시작하였으므로, n-1일이 최대일.
        if (i + t <= n)
        {
            dp[i + t] = max(dp[i + t], mx + c);
            res = max(dp[i + t], res);
        }
	}

    cout << res;
}
