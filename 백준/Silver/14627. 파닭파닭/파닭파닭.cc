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

    int s, c;
    cin >> s >> c;
    
    long long sum = 0;
    vector<int> v(s);
    for (int i = 0; i < s; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    long long start = 1, end = 1000000000, used = 0;
    while (start <= end)
    {
        long long mid = (start + end) / 2;

        int cnt = 0;
        for (int i = 0; i < s; i++)
        {
            cnt += v[i] / mid;
        }

        if (cnt >= c)
        {
            start = mid + 1;
            used = max(used, mid);
        }
        else end = mid - 1;
    }

    cout << sum - used * c;
}
    