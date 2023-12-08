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
using namespace std;

int n, d, res=0;
int dp[10001];
vector<pair<int, int>> v[10001];

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> d;
    
    for (int i = 0; i < n; i++)
    {
        int start, end, dist;
        cin >> start >> end >> dist;
        if (end > d || dist > end - start) continue;
        v[end].push_back({ start,dist });
    }

    sort(v->begin(), v->end(), cmp);

    dp[0] = 0;

    for (int i = 1; i <= d; i++)
    {
        dp[i] = dp[i - 1] + 1;
        for (int j = 0; j < v[i].size(); j++)
        {
            dp[i] = min(dp[i], dp[v[i][j].first] + v[i][j].second);
        }
    }

    cout << dp[d];
}
