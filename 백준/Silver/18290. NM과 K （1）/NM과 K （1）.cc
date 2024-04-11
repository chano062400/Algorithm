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

int n, m, k, sum = 0, res = -999999999;
int arr[11][11];
bool visited[11][11];
vector<pair<int, int>> v;

bool IsNotAdjacent(int x, int y)
{
    for (int i = 0; i < v.size(); i++)
    {
        int dif = abs(x - v[i].first) + abs(y - v[i].second);
        if (dif <= 1) return false;
    }
    return true;
}

void back(int sum)
{
    if (v.size() == k)
    {
        res = max(res, sum);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!visited[i][j] && IsNotAdjacent(i, j))
            {
                visited[i][j] = 1;
                v.push_back({ i,j });
                back(sum + arr[i][j]);
                v.pop_back();
                visited[i][j] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    back(0);

    cout << res;
}
