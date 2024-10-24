#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int>v(n), lis;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    lis.push_back(v[0]);

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > lis.back())
        {
            lis.push_back(v[i]);
        }
        else
        {
            int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            lis[idx] = v[i];
        }
    }

    cout << n - lis.size();
}