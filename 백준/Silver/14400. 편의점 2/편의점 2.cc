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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x, y;
    vector<pair<int, int>> xy;

    for (int i = 0; i < n; i++)
    {
        int posx, posy;
        cin >> posx >> posy;
        x.push_back(posx);
        y.push_back(posy);
        xy.push_back({ posx,posy });
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    pair<int, int> pos = { x[n / 2], y[n / 2] };

    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        res += abs(pos.first - xy[i].first) + abs(pos.second - xy[i].second);
    }

    cout << res;
}
