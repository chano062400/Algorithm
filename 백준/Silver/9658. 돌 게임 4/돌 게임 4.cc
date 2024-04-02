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
    
    int n;
    cin >> n;

    int dp[1001] = {};
    
    for (int i = 1; i <= n; i++)
    {
        if (i % 7 == 1 || i % 7 == 3)
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = 1;
        }
    }

    if (dp[n] == 0) cout << "CY";
    else cout << "SK";
}
