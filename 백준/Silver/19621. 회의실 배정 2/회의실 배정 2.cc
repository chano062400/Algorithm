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

int n;
int dp[1001][2] = {};

struct Info
{
    int start =0, end = 0 , people = 0;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    
    vector<Info> v(n+1);
    int maxtime = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].start >> v[i].end >> v[i].people;
    }

    dp[1][1] = dp[2][0] = v[1].people;
    dp[2][1] = v[2].people;

    for (int i = 2; i <= n; i++)
    {
        // 이번 회의에 참석X
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        
        // 이번 회의에 참석O
        dp[i][1] = max(dp[i - 2][0] + v[i].people, dp[i - 2][1] + v[i].people);
    }

    cout << max(dp[n][0], dp[n][1]);
}
