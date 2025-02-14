#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "memory.h"
#include <set>
#include <unordered_set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
#include <limits.h>
#include <list>
using namespace std;

int n, m;
vector<int> v[100001];
bool visited[100001];
int sum[100001], res[100001];

void dfs(int cur, int val)
{
    if (visited[cur] || cur == -1) return;

    visited[cur] = true;

    res[cur] += val;

    for (int i = 0; i < v[cur].size(); i++)
    {
        int next = v[cur][i];
        dfs(next, val + sum[next]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        int idx;
        cin >> idx;
        // 상사 idx의 부하직원.
        v[idx].push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        int idx, val;
        cin >> idx >> val;
        sum[idx] += val;
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
}