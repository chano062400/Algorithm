#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
using namespace std;

int n, m;
int arr[100][100];
int visited[100][100];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int bfs()
{
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    visited[0][0]++;

    int cnt = 0;
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (arr[nx][ny] == 1)
            {
                visited[nx][ny]++;
                if (visited[nx][ny] >= 2)
                {
                    arr[nx][ny] = 0;
                }
                cnt++;
            }
            else if(!arr[nx][ny] && !visited[nx][ny])
            {
                q.push({ nx,ny });
                visited[nx][ny] = 1;
            }
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }   

    int time = 0;
    while (bfs())
    {
        time++;
    }

    cout << time;
}

