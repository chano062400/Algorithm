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



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    int dp[41] = { 0, };
    dp[0] = 1; // 무조건 답은 1 이상.
    
    for (int i = 1; i < str.length(); i++)
    {
        if ((str[i] - '0') + (str[i - 1] - '0') * 10 < 35 && str[i - 1] != '0')
        {
            if (i == 1) dp[i] = 1;
            else dp[i] += dp[i - 2];
        }
        if (str[i] != '0') dp[i] += dp[i - 1];
    }

    cout << dp[str.length() - 1];
}
