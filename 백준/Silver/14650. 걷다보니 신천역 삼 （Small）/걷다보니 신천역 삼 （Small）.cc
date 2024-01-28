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

int n, cnt=0;
vector<int> v;

void bt()
{
    if (v.size() >= n)
    {
        string str ="";
        for (auto num : v) str += to_string(num);
        if (stoi(str) % 3 == 0) cnt++;
        return;
    }

    if (v.empty())
    {
        for (int i = 1; i <= 2; i++)
        {
            v.push_back(i);
            bt();
            v.pop_back();
        }
    }
    else
    {
        for (int i = 0; i <= 2; i++)
        {
            v.push_back(i);
            bt();
            v.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    bt();

    cout << cnt;

    return 0;
};

