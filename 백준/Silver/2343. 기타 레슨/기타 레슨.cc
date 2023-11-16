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
using namespace std;

int n, m, total=0,res,mn;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	
    cin >> n >> m;

    vector<int>v;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
        total += num;
        mn = max(mn, num);
    }

    int start = mn, end = total;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        int sum = 0, div = 1;
        for (int i = 0; i < v.size(); i++)
        {
            if (sum + v[i] > mid)
            {
                div++;
                sum = 0;
            }
            sum += v[i];
        }

        if (div <= m)
        {
            end = mid - 1;
            res = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << res;
}