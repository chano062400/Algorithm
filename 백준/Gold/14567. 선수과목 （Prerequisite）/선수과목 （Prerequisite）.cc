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
vector<int> out[1001];
int Time[1001], in[1001];

void bfs()
{
    queue<int> q;
    
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
            Time[i] = 1;
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < out[cur].size(); i++)
        {
            int next = out[cur][i];

            if (--in[next] == 0)
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
        out[first].push_back(second);
        in[second]++;
    }

    bfs();

    for (int i = 1; i <= n; i++)
    {
        cout << Time[i] << " ";
    }
}
