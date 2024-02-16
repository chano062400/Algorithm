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

int n, res;
int arr[100001] = { 0, }, dp[100001][2] = { 0, }; // [0] - 제거 X , [1] - 현재 수 제거.

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    dp[1][0] = arr[1];
    res = arr[1];

    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = max(dp[i-1][0] + arr[i], arr[i]);
        dp[i][1] = max(dp[i-1][0], dp[i - 1][1] + arr[i]);
        res = max(res, max(dp[i][0], dp[i][1]));
    }

    cout << res;

};

