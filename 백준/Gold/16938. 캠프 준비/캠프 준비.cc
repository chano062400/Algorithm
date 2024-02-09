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

int n, l, r, x, res;
vector<int> v, v2;
bool visited[16];

void back(int size, int index)
{
    if (v2.size() == size)
    {
        long long sum = 0;
        for (auto number : v2) sum += number;
        if (sum >= l && sum <= r)
        {
            int mn = *min_element(v2.begin(), v2.end());
            int mx = *max_element(v2.begin(), v2.end());

            if (mx - mn >= x) res++;
        }
        return;
    }

    for (int i = index; i < v.size(); i++)
    {
        int num = v[i];
        if (!visited[i])
        {
            visited[i] = true;
            v2.push_back(num);
            back(size, i);
            v2.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for (int i = 2; i <= v.size(); i++)
    {
        back(i,0);
    }
    
    cout << res;
};

