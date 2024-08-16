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

int n, cnt = 0;
bool visited[500001] = { 0 };
vector<int> v[500001];

void dfs(int cur, int depth)
{
    if (v[cur].size() == 1 && cur != 1) // 리프노드
    {
        cnt += depth;
        return;
    }
    for (int i = 0; i < v[cur].size(); i++)
    {
        if (!visited[v[cur][i]])
        {
            visited[v[cur][i]] = true;
            dfs(v[cur][i], depth + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1, 0);

    if (cnt % 2)
    {
        cout << "Yes";
    }
    else cout << "No";
}
