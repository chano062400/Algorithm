#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "memory.h"
#include <set>
#include <unordered_set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
#include <limits.h>
#include <list>
using namespace std;

char arr[5][5];
int res = 0;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
vector<int> v;

bool check()
{
    vector<bool> visited(25, 0);
    queue<int> q;
    q.push(v[0]);
    visited[v[0]] = true;
    int cnt = 1, sCnt = (arr[v[0] / 5][v[0] % 5] == 'S');

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int cx = cur / 5;
        int cy = cur % 5;

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int next = nx * 5 + ny;
            if (nx < 0 || nx > 4 || ny < 0 || ny > 4 || visited[next]) continue;
 
            if (find(v.begin(), v.end(), next) != v.end())
            {
                visited[next] = true;
                q.push(next);
                cnt++;
                sCnt += arr[nx][ny] == 'S';
            }
        }
    }
    
    return (cnt == 7 && sCnt >= 4);
}

void back(int index)
{
    if (v.size() == 7)
    {
        if (check()) res++;
        return;
    }

    for (int i = index; i < 25; i++)
    {
        v.push_back(i);
        back(i + 1);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 5; i++) 
    {
        string str;
        cin >> str;
        for (int j = 0; j < 5; j++) 
        {
            arr[i][j] = str[j];
        }
    }
   
    back(0);
    
    cout << res << '\n';
    return 0;
}