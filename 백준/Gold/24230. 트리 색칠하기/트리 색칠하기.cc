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

int n, res;
vector<int> color(200001), v[200001];
bool visited[200001];

void paint(int cur, int prevcolor)
{
    if (color[cur] != prevcolor) res++;
    visited[cur] = true;
 
    for (int i = 0; i < v[cur].size(); i++)
    {
        int next = v[cur][i];
        if (!visited[next])
        {
            paint(next, color[cur]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

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

    paint(1, 0);

    cout << res;
}

