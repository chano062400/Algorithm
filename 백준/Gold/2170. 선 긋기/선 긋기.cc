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

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        v.push_back({ s, e });
    }

    sort(v.begin(), v.end());

    int start = -1e9, end = -1e9, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (end < v[i].first)
        {
            sum += end - start;
            start = v[i].first;
        }
            
        if (end < v[i].second)
        {
            end = v[i].second;
        }
    }

    sum += end - start;

    cout << sum;
}
