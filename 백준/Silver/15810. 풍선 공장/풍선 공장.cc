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

int n, m;
long long balloon[1000001];
#define MAX 10000000000000
long long res = MAX, mn = 1000001;;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> balloon[i];
        mn = min(mn, balloon[i]);
    }

    long long start = mn, end = MAX, sum;
    while (start <= end)
    {
        sum = 0;
        long long mid = (start + end) / 2;
        
        for (int i = 1; i <= n; i++)
        {
            sum += mid / balloon[i];
        }
        if (sum >= m)
        {
            res = min(res, mid), end = mid - 1;
            end = mid - 1;        
        }
        else start = mid + 1;
    }

    cout << res;
}
