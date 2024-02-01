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

int n, res = -1;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int spend, limit;
        cin >> spend >> limit;
        v.push_back({ spend,limit });
    }

    sort(v.begin(), v.end(), cmp);

    int limit = v.front().second - v.front().first;
    bool can = true;
    for (int i = 0; i <= limit; i++)
    {
        int tmp = i;
        for (int j = 0; j < v.size(); j++)
        {
            tmp += v[j].first;
            if (tmp > v[j].second)
            {
                can = false;
                break;
            }
        }
        if(can) res = max(res, i);
    }

    cout << res;
    

};

