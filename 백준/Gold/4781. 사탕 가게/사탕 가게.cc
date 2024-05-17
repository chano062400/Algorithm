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

long long dp[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while (1)
    {
        memset(dp, 0, sizeof(dp));

        int t;
        double m;
        cin >> t >> m;
        if (t == 0 && m == 0.00) break;
        
        /* N / (2의 거듭제곱)의 꼴로 나타낼 수 없는 모든 실수는 정확하게 표현되지 않기 때문에,
        int로 바꿀 땐 소숫점 아래를 버리는데 대부분은 정확히 나오지만,
        0.29같은 몇몇 수들이 100을 곱하면 28.999999... 이런 식으로 자연수보다 살짝 작게 나와서 이런걸 방지하기위해,
        적당한 작은 수(0.5)를 더해서 소숫점 아래를 버림해도 문제 없도록 함*/
        int M = static_cast<int>(m * 100 + 0.5);
        vector<pair<int, int>> v;
        for (int i = 0; i < t; i++)
        {
            int a;
            double b;
            cin >> a >> b;
            int B = static_cast<int>(b * 100 + 0.5);
            v.push_back({ a , B});
        }

        for (int i = 0; i < t; i++)
        {
            for (int j = v[i].second; j <= M; j++)
            {
                dp[j] = max(dp[j - v[i].second] + v[i].first, dp[j]);
            }
        }
        
        long long res = 0;
        for (int i = 0; i <= M; i++)
        {
            res = max(res, dp[i]);
        }
        cout << res << '\n';

    }
}
  