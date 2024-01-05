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
using namespace std;

int t, n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        
        vector<int> v, dif(n);

        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            v.push_back(num);
        }
        
        sort(v.begin(), v.end());
        int sub = 0;
        for (int i = 0; i < n; i++)
        {
            int num = v[i];
            if (i % 2 == 0)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dif[j] == 0)
                    {
                        dif[j] = num;
                        break;
                    }
                }
            }
            else
            {
                for (int h = n - 1; h >= 0; h--)
                {
                    if (dif[h] == 0)
                    {
                        dif[h] = num;
                        break;
                    }
                }
            }
        }


        int res = abs(dif.front() - dif.back());
        for (int i = 0; i < n-1; i++)
        {
            res = max(res, abs(dif[i] - dif[i + 1]));
        }

        cout << res << '\n';
    }
}
