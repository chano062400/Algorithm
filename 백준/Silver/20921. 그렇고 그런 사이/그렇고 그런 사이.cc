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

int n, k;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> k;

    int temp = n;
    while (k > 0)
    {
        if (k < temp)
        {
            v.push_back(k + 1);   
            k -= k;
        }
        else
        {
            v.push_back(temp);
            k -= temp - 1;
            temp--;
        }
    }

    if (v.size() < n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (find(v.begin(), v.end(), i) == v.end())
            {
                v.push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}

