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
 
    int n, k, res = 0;
    cin >> n >> k;
    vector<int> v(n), dist;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n - 1; i++)
    {
        dist.push_back(abs(v[i] - v[i + 1]));
    }

    sort(dist.begin(), dist.end());

    int idx = dist.size() - (k - 1);
    for (int i = 0; i < idx; i++)
    {
        res += dist[i];
    }

    cout << res;
}
