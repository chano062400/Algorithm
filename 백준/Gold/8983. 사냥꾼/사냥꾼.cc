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

    int m, n, l, res = 0;
    cin >> m >> n >> l;
    
    vector<int> v(m);
    vector<pair<int, int>> pos;
    set<pair<int, int>> hunted;

    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        int x ,y;
        cin >> x >> y;
        if (y > l || abs(x - v.back() > l)) continue;
        pos.push_back({ x,y });
    }

    for (int i = 0; i < pos.size(); i++)
    {
        int x = pos[i].first, y = pos[i].second;
        int start = 0, end = m - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (abs(v[mid] - x) + y <= l)
            {
                res++;
                break;
            }
            else
            {
                if (v[mid] <= x)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
    }

    cout << res;
}
