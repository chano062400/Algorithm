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
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, res = 0;
    cin >> n;
    
    vector<int> num(n), dp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    reverse(num.begin(), num.end());


    for (int i = 0; i < n; i++)
    {
        dp[i] = num[i];
        for (int j = 0; j < i; j++)
        {
            if (num[i] > num[j])
            {
                dp[i] = max(dp[j] + num[i], dp[i]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        res = max(res, dp[i]);
    }
    
    cout << res;
}
