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
    
    int n, m;
    cin >> n >> m;

    vector<int> v(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }

    int start = 1, end = *max_element(v.begin(), v.end()), res = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int cnt = 0;

        for (int i = 0; i < m; i++)
        {
            if (v[i] >= mid) cnt += v[i] / mid;
        }

        if (cnt < n)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
            res = max(res, mid);
        }
    }
       
    cout << res;
}
