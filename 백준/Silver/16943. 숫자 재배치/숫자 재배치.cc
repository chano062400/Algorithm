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

string a, b, num="";
int res = -1;
bool check[10];

void back()
{
    if (num.length() == a.length())
    {
        int temp = stoi(num);
        
        if (temp < stoi(b))
        {
            res = max(res, temp);
        }
        return;
    }

    for (int i = 0; i < a.length(); i++)
    {
        if (!check[i])
        {
            if (num.empty() && a[i] == '0') continue;

            check[i] = 1;
            num.push_back(a[i]);
            back();
            num.pop_back();
            check[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> a >> b;

    if (a.length() > b.length())
    {
        cout << -1 << '\n';
        return 0;
    }
    else
    {
        back();
        cout << res << '\n';
    }
}
