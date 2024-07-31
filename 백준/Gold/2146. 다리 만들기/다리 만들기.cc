#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include "memory.h"

using namespace std;

int arr[100][100];
bool visited[100][100];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n, label = 1,res = 100000;
vector<pair<int, int>> v;

void dfs(int y, int x, int landlabel)
{
    visited[y][x] = 1;
    arr[y][x] = landlabel;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx] && arr[ny][nx] != -1)
        {
            arr[ny][nx] = landlabel;
            visited[ny][nx] = 1;
            dfs(ny, nx, landlabel);
        }
    }

}

void bfs(int y, int x)
{
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));

    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < v.size(); i++)
        {
            if (arr[cy][cx] != arr[v[i].first][v[i].second])
            {
               int dist = abs(cy - v[i].first) + abs(cx - v[i].second) - 1;
                if (dist < res)
                    res = dist;
            }
        }

        for (int j = 0; j < 4; j++)
        {
            int ny = cy + dy[j];
            int nx = cx + dx[j];

            if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx] && arr[ny][nx] != -1)
            {
                visited[ny][nx] = 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            arr[i][j] -= 1;
            if(arr[i][j] != -1)
                 v.push_back(make_pair(i, j));
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && arr[i][j] != -1)
                dfs(i, j,label++);
        }
    }

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && arr[i][j] != -1)
                bfs(i, j);
        }
    }

    cout << res;
}           
