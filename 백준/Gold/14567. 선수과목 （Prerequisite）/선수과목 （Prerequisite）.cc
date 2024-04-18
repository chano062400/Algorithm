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

int n, m;
vector<int> v[1001];
int Time[1001] = {}, cnt[1001] = {};

void bfs()
{
    queue<int> q;
    
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 0)
        {
            q.push(i);
            Time[i] = 1;
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i];

            if (--cnt[next] == 0)
            {
                q.push(next);
                Time[next] = Time[cur] + 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int first, second;
        cin >> first >> second;
        v[first].push_back(second);
        cnt[second]++;
    }

    bfs();

    for (int i = 1; i <= n; i++)
    {
        cout << Time[i] << " ";
    }
}
