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

int n, k, idx = 0;
vector<int> v, num = { 1,2,3 };

void back(int target, int sum)
{
    if (sum > n) return;

    if (sum == n)
    {
        if (idx == k-1)
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (i == v.size() - 1)
                {
                    cout << v[i];
                }
                else
                {
                    cout << v[i] << "+";
                }
            }
        }
        idx++;
        return;
    }
    
    for (int i = 0; i < 3; i++)
    {
        v.push_back(num[i]);
        back(target, sum + num[i]);
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    back(n, 0);

    if (idx <= k - 1)
    {
        cout << -1;
    }
}
