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

int n, m, cnt = 0;

void dfs(int index, int num)
{
    if (num == m - n)
    {
        cnt++;
        return;
    }

    for (int i = index; i < n; i++)
    {
        dfs(i, num + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    dfs(0, 0);

    cout << cnt;
};

