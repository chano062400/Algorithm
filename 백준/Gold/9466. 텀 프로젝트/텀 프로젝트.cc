#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int visited[100001]; // 0: 미방문, 1: 방문 중, 2: 방문 완료
int cnt;

void dfs(int cur, vector<int>& v)
{
    visited[cur] = 1; // 방문 중
    int next = v[cur];

    if (visited[next] == 0) // 미방문 노드
    {
        dfs(next, v);
    }
    else if (visited[next] == 1) // 사이클 발견
    {
        cnt++;
        for (int i = next; i != cur; i = v[i])
            cnt++;
    }
    // 방문 완료 표시
    visited[cur] = 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }

        memset(visited, 0, sizeof(visited));
        cnt = 0;

        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i, v);
            }
        }

        cout << n - cnt << '\n';
    }
}