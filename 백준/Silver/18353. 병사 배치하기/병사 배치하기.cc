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

int binary_search(vector<int>& lis, int num, int start, int end)
{
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (num > lis[mid]) start = mid + 1;
        else end = mid;
    }

    return end;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, res = 0;
    cin >> n;
    vector<int> v(n), lis;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    reverse(v.begin(), v.end());

    lis.push_back(v[0]);

    for (int i = 1; i < n; i++)
    {
        if (v[i] > lis.back())
        {
            lis.push_back(v[i]);
            res = lis.size() - 1;
        }

        int idx = binary_search(lis, v[i],0,lis.size());
        lis[idx] = v[i];
    }

    cout << n - (res + 1);
}
