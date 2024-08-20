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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, res = 0;
        cin >> n;

        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((v[i] + v[j]) % 2 == 0)
                {
                    int start = 0, end = n;
                    
                    while (start <= end)
                    {
                        int mid = (start + end) / 2;
                        int target = (v[i] + v[j]) / 2;
                        
                        if (v[mid] == target)
                        {
                            res++;
                            break;
                        }
                        else if (v[mid] > target) end = mid - 1;
                        else start = mid + 1;
                    }
                }
            }
        }

        cout << res << '\n';
    }
}
