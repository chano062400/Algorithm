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

int n;
vector<long long> v;

void dfs(int num, string str)
{
    if (!str.empty())
    {
        string temp = str;
        reverse(temp.begin(), temp.end());
        v.push_back(stoll(temp));
    }

    for (int i = num+1; i <= 9; i++)
    {
        str += to_string(i);
        dfs(i, str);
        str.pop_back();
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0; i <= 9; i++)
    {
        dfs(i, to_string(i));
    }

    sort(v.begin(), v.end());
    
    if (n > v.size()) cout << -1;
    else cout << v[n-1];
};

