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
    vector<int> v(n),lis;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    lis.push_back(v[0]);

    for (int i = 1; i < n; i++)
    {
        if (v[i] > lis.back())
        {
            lis.push_back(v[i]);
            continue;
        }

        auto it = lower_bound(lis.begin(), lis.end(), v[i]);
        *it = v[i];
    }

    cout << n - lis.size();
}

    