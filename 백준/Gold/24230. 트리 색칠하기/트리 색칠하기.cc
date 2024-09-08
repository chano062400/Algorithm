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

int n, depth[200001], res;
bool visited[200001];
vector<int> color(200001), v[200001];

void finddepth(int index, int dep)
{
    for (int i = 0; i < v[index].size(); i++)
    {
        int next = v[index][i];
        if (depth[next] == 0)
        {
            depth[next] = dep;
            finddepth(next, dep + 1);
        }
    }
}

void paint(int index, int previndex)
{
    if (depth[previndex] > depth[index] || visited[index]) return;
    visited[index] = true;

    for (int i = 0; i < v[index].size(); i++)
    {
        int next = v[index][i];
        if (color[next] != 0 && !visited[next])
        {
            if (color[index] != color[next]) res++;
        }
        
        paint(next, index);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    depth[1] = 1;

    for (int i = 1; i <= n; i++)
    {
        cin >> color[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(v[i].begin(), v[i].end());
    }

    finddepth(1, 2);

    if (color[1] != 0) res++;
    paint(1, 0);

    cout << res;
}

