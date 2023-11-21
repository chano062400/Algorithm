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

int n,a,b, res =987654321;
int arr[10001], jump[10001];
bool visited[10001];

void bfs(int from, int to)
{
    queue<int> q;
    q.push(from);
    visited[from] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == to) return;

        for (int i = cur + arr[cur]; i <= n; i += arr[cur])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                jump[i] = jump[cur] + 1;
                q.push(i);
            }
        }

        for (int i = cur - arr[cur]; i >= 1; i -= arr[cur])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                jump[i] = jump[cur] + 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    memset(arr, 0, sizeof(arr));
    memset(jump, 0, sizeof(jump));
    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    cin >> a >> b;

    bfs(a,b);

    if (jump[b] == 0) cout << -1;
    else cout << jump[b];
}