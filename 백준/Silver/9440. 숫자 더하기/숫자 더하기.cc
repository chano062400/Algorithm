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

    while (1)
    {
        int n, res = 9876543210;
        cin >> n;
        if (n == 0) break;
        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        if(v[0] == 0)
        {
            for (int i = 2; i < n; i++)
            {
                if (v[i] != 0)
                {
                    swap(v[0], v[i]);
                    break;
                }
            }
        }
        
        if (v[1] == 0)
        {
            for (int i = 3; i < n; i++)
            {
                if (v[i] != 0)
                {
                    swap(v[1], v[i]);
                    break;
                }
            }
        }

        string n1, n2;
        
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || i % 2 == 0)
            {
                n1 += to_string(v[i]);
            }
            else if(i % 2)
            {
                n2 += to_string(v[i]); 
            }
        }

        int sum = stoi(n1) + stoi(n2);

        cout << min(res,sum) << '\n';

    }

}
