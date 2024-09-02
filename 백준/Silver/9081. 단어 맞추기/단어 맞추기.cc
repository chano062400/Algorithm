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

bool cmp(const char c1, const char c2)
{
    return c1 < c2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        vector<string> v;
        int idx = 0;
        do
        {
            v.push_back(str);
            if (idx == 1) break;
            idx++;
        } while (next_permutation(str.begin(), str.end(), cmp));

        cout << v.back() << '\n';
    }
}

