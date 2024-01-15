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

int n, dp[300001];
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0; ;i++)
    {
        int num = i * (i + 1) * (i + 2) / 6;
        if (num > 300000) break;
        v.push_back(num);
    }

    fill(dp, dp + 300001, 987654321);

    for (int i = 0; i < v.size(); i++) dp[v[i]] = 1;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = v[i]; j <= n; j++)
        {
            dp[j] = min(dp[j], dp[j - v[i]] + 1);
        }
    }

    cout << dp[n];
};

