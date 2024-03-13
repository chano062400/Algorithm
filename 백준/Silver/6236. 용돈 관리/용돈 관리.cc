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
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    long long res = 987654321;
    cin >> n >> m;

    int sum = 0;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
        sum += num;
    }

    long long start = *max_element(v.begin(), v.end()),  end = sum;
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        int cnt = 1;

        long long temp = mid;
        for (auto num : v)
        {
            if (num > temp)
            {
                temp = mid;
                cnt++;
            }

            temp -= num;
        }

        if(cnt > m) start = mid + 1;
        else
        {
            res = mid;
            end = mid - 1;
        }
    }
    
    cout << res;
}
