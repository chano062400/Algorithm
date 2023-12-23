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

int n, res = 0;
bool nozero = true;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    

    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    while (1)
    {
        bool allzero = true;
        bool alleven = true;

        for (auto& n : v)
        {
            if (n != 0) allzero = false;
            if (n % 2 == 1)
            {
                n -= 1;
                alleven = false;
                res++;
            }
        }

        if (allzero) break;

        if (alleven)
        {
            for (auto& n : v) n /= 2;
            res++;
        }

    }

    cout << res;
}
