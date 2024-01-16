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

int n, m, k;

int dfs(int x, int y, int tx, int ty)
{
    if (x == tx && y == ty) return 1;
    if (x > tx || y > ty) return 0;
    return dfs(x + 1, y, tx, ty) + dfs(x, y + 1, tx, ty);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;

    if (k == 0) dfs(1, 1, n, m);
    int res = dfs(1, 1, (k - 1) / m + 1, (k - 1) % m + 1) * dfs((k - 1) / m + 1, (k - 1) % m + 1, n, m);
    cout << res;
};

