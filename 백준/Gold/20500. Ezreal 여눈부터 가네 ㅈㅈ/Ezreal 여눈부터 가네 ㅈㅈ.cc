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

int dp[1516];

int factorial(int num)
{
    int res = 1;
    for (int i = num; i >= 1; i--)
    {
        res *= i; 
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    
    for (int i = 3; i <= 1515; i++)
    {
        dp[i] = (((dp[i - 2] * 2) % 1000000007) + dp[i-1]) % 1000000007;
    }
    
    cout << dp[n];
}
