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

int n, arr[4];
long long mx = -1000000001, mn = 1000000001;
vector<int> v;

void back(int idx, int cnt, long long num)
{
    if (cnt == n - 1)
    {
        mx = max(mx, num);
        mn = min(mn, num);

        return;
    }

    for (int i = idx; i < v.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[j] > 0)
            {
                arr[j]--;
                if (j == 0)
                {
                    back(i+1,cnt + 1, num + v[i]);
                }
                if (j == 1)
                {
                    back(i+1,cnt + 1, num - v[i]);
                }
                if (j == 2)
                {
                    back(i+1,cnt + 1, num * v[i]);
                }
                if (j == 3)
                {
                    back(i+1,cnt + 1, num / v[i]);
                }
                arr[j]++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }

    back(1, 0, v[0]);

    cout << mx << '\n' << mn << '\n';
}
