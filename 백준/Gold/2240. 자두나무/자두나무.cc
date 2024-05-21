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

int dp[1001][32][3], tree[1001][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int t, w;
    cin >> t >> w;
    for (int i = 1; i <= t; i++)
    {
        int num;
        cin >> num;
        tree[i][num] = 1;
    }

    dp[1][0][1] = tree[1][1];
    dp[1][1][2] = tree[1][2];

    int res = max(dp[1][0][1], dp[1][1][2]);

    for (int i = 2; i <= t; i++) {
        for (int j = 0; j <= w; j++) {
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + tree[i][1];
            dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]) + tree[i][2];
            
            res = max(max(res, dp[i][j][1]), dp[i][j][2]);
        }
    }

    cout << res;
}
    