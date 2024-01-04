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

int n, mx=0 ,idx;
long long res = 0;
vector<int> grow, first;
bool cut[100001];

bool cmp(pair<int, int>p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int len;
        cin >> len;
        first.push_back(len);
    }
    
    for (int i = 0; i < n; i++)
    {
        int len;
        cin >> len;
        grow.push_back(len);
    }

    vector<pair<int, int>> tree;
    for (int i = 0; i < n; i++)
    {
        tree.push_back({ first[i] , grow[i]});
    }

    sort(tree.begin(), tree.end(),cmp);

    for (int i = 0; i < n; i++)
    {
        res += tree[i].first + (tree[i].second * i);
    }

    cout << res;

}
