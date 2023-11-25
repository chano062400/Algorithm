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

double arr[51];
int n, res=0, cnt;
double inc, mx;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        mx = 10000000000;

        cnt = 0;

        for (int j = i - 1; j >= 1; j--) // 왼쪽 (기울기 +)
        {
            inc = (arr[i] - arr[j]) / ((double)i - (double)j);
            if (inc < mx)
            {
                mx = inc;
                cnt++;
            }
        }

        mx = -1000000000;

        for (int h = i + 1; h <= n; h++) // 오른쪽 (기울기 -)
        {
            inc = (arr[h] - arr[i]) / ((double)h - (double)i);
            if (inc > mx)
            {
                mx = inc;
                cnt++;
            }
        }

        res = max(res, cnt);
    }

    cout << res;

}