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

    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> arrow;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    arrow.push_back(v[0]);

    for (int i = 0; i < n; i++)
    {
        bool bfind = false;
        for (int j = 0; j < arrow.size(); j++)
        {
            if (v[i] == arrow[j])
            {
                arrow[j]--;
                bfind = true;
                break;
            }
        }
        if (!bfind)
        {
            arrow.push_back(v[i]-1);
        }
    }

    cout << arrow.size();

    return 0;
}
  