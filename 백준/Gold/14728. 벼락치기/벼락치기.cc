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
using namespace std;

int n, t, idx;
int dp[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> t;

    vector<pair<int, int>> v(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = t; j >= v[i].first; j--) // 앞에서부터 돌리면 중복이 발생 50 - 40, 100 - 80 ...
        {
            dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
        }
    }

    cout << dp[t];
}
