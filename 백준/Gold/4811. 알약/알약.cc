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

// [w개수][h개수]
long long dp[31][31];

long long dfs(int w, int h)
{
    if (h == -1) return 0;
    if (w == 0) return 1; 

    long long& res = dp[w][h];
    if (res != -1) return res;

    res = dfs(w - 1, h + 1) + dfs(w, h-1);

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    while (1)
    {
        int n;
        cin >> n;
        if (n == 0) break;

        cout << dfs(n, 0) << '\n';
    }

}

    