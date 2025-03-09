 #include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include "memory.h"
#include <set>
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

// 0 중앙 1 북 3 남 2 동 4 서
int dp[100001][5][5];
vector<int> v;

bool isopposite(int cur, int next)
{
    if (cur == 1 && next == 3) return true;
    else if (cur == 3 && next == 1) return true;
    else if (cur == 2 && next == 4) return true;
    else if (cur == 4 && next == 2) return true;
    else return false;
}

int getcost(int cur, int next)
{
    if (cur == 0) return 2;
    else if (cur == next) return 1;
    else if (isopposite(cur, next)) return 4;
    return 3;
}

int solve(int idx, int left, int right)
{
    if (idx == v.size() - 1) return 0;
    if (dp[idx][left][right] != -1) return dp[idx][left][right];

    // 왼쪽 발을 움직인 경우.
    int leftcost = solve(idx + 1, v[idx + 1], right) + getcost(left, v[idx + 1]);
    // 오른쪽 발을 움직인 경우.
    int rightcost = solve(idx + 1, left, v[idx + 1]) + getcost(right, v[idx + 1]);

    return dp[idx][left][right] = min(leftcost, rightcost);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    memset(dp, -1, sizeof(dp));
    
    v.push_back(0);

    while (1)
    {
        int dir;
        cin >> dir;
        if (dir == 0) break;
        v.push_back(dir);
    }
    
    cout << solve(0, 0, 0);
}