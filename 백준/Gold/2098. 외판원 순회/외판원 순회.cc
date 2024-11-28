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

int n;
int arr[16][16];
int cost[16][1 << 16];
#define MAX 987654321

int dfs(int curcity, int curbit)
{
    // 모든 도시를 다 돈 경우.
    if (curbit == (1 << n) - 1)
    {
        // 시작 도시(0)로 다시 돌아가는 길이 없다면
        if (arr[curcity][0] == 0)
        {
            return MAX;
        }
        // 길이 있다면
        else
        {
            return arr[curcity][0];
        }
    }

    // 이미 왔던 도시라면
    if (cost[curcity][curbit] != -1)
    {
        return cost[curcity][curbit];
    }

    cost[curcity][curbit] = MAX;

    for (int i = 0; i < n; i++)
    {
        // 해당 도시로 가는 길이 없다면 continue
        if (arr[curcity][i] == 0) continue;
        // 이미 갔던 도시라면 continue
        if ((curbit & (1 << i)) == (1 << i)) continue;

        cost[curcity][curbit] = min(cost[curcity][curbit], arr[curcity][i] + dfs(i, curbit | (1 << i)));
    }

    return cost[curcity][curbit];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> arr[i][j];
        }
    }

    memset(cost, -1, sizeof(cost));
    cout << dfs(0, 1 << 0);
}

