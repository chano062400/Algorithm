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
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, res = 0;
    cin >> n;
    vector<int> v(n+1), sum(n+1);
    
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        sum[i] = sum[i - 1] + v[i]; // 누적합
    }

    // 벌 -> 벌통 <- 벌
    for (int i = 2; i < n; i++)
    {
        // sum[i] - sum[1] = 왼쪽에서 시작한 벌.
        // sum[n-1] - sum[i-1] 오른쪽에서 시작한 벌
        int cursum = (sum[i] - sum[1]) + (sum[n - 1] - sum[i - 1]);
        res = max(res, cursum);
    }

    // 벌 -> 벌 -> 벌통
    for (int i = 2; i < n; i++)
    {
        // sum[n] - sum[1] - v[i] - 왼쪽 맨 끝에서 출발하는 벌. (- v[i] = 중간에 있는 벌이 시작한 장소에선 꿀X)
        // sum[n] - sum[i] = 중간에서 오른쪽 끝으로시작하는 벌.
        int cursum = (sum[n] - sum[1] - v[i]) + (sum[n] - sum[i]);
        res = max(res, cursum);
    }

    // 벌통 <- 벌 <- 벌
    for (int i = 2; i < n; i++)
    {
        // sum[n-1] - v[i] - 오른쪽 맨 끝에서 출발하는 벌
        // sum[i-1] = 중간에서 왼쪽 끝으로 출발하는 벌,
        int cursum = (sum[n - 1] - v[i]) + sum[i - 1];
        res = max(res, cursum);
    }
    
    cout << res;
}
