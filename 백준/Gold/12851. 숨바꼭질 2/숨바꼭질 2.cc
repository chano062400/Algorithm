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

int n, k, cnt = 0;
int arr[100001];
bool visited[100001];
vector<int> v;

void bfs(int start)
{
    queue<pair<int, int>> q;
    q.push({ 0,start });
    visited[start] = 1;

    while (!q.empty())
    {
        int curcnt = q.front().first;
        int cur = q.front().second;
        q.pop();

        visited[cur] = 1;

        if (cur == k)
        {
            v.push_back({ curcnt });
        }

        if (cur + 1 <= 100000 && !visited[cur + 1])
        {
            q.push({ curcnt + 1, cur + 1 });
        }

        if (cur - 1 >= 0 && !visited[cur - 1])
        {
            q.push({ curcnt + 1, cur - 1 });
        }

        if (cur * 2 <= 100000 && !visited[cur * 2])
        {
            q.push({ curcnt + 1, cur * 2 });
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    bfs(n);

    sort(v.begin(), v.end());

    int min = *min_element(v.begin(), v.end()), res = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == min)
        {
            res++;
        }
    }

    cout << min << '\n' << res << '\n';
}
    