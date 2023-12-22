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
using namespace std;

int n, arr[100001], cnt = 0;
bool visited[100001];

void bfs(int start)
{
    queue<int> q;
    visited[start] = 1;
    q.push(start);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur + arr[cur] <= n && !visited[cur + arr[cur]])
        { 
            q.push(cur + arr[cur]); 
            visited[cur + arr[cur]] = 1;
        }
        if (cur - arr[cur] >= 1 && !visited[cur - arr[cur]])
        { 
            q.push(cur - arr[cur]); 
            visited[cur - arr[cur]] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int start;
    cin >> start;

    bfs(start);

    for (int i = 1; i <= n; i++)
    {
        if (visited[i]) cnt++;
    }

    cout << cnt;
}
