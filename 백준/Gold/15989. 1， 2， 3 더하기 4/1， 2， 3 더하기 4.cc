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

int dp[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    dp[0] = 1;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 10000; j++)
        {
            if (j - i >= 0)
            {
                dp[j] += dp[j - i];
            }
        }
    }

    while (n--)
    {
        int num;
        cin >> num;

        cout << dp[num] << '\n';
    }
}