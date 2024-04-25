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

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    vector<int> v, dp;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    dp.push_back(v[0]);
    for (int i = 1; i < n; i++)
    {
        if (v[i] > dp.back())
        {
            dp.push_back(v[i]);
            continue;
        }

        auto it = lower_bound(dp.begin(), dp.end(), v[i]);
        *it = v[i];
    }

    cout << dp.size() << '\n';

}
    