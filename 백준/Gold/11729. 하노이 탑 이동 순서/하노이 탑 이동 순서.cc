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

int n;
vector<pair<int, int>> v;

void hanoi(int num, int from, int by, int to)
{
    if (num == 1)
    {
        v.push_back({ from,to });
    }
    else
    {
        hanoi(num - 1, from, to, by);

        v.push_back({ from, to });

        hanoi(num - 1, by, from, to);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    hanoi(n, 1, 2, 3);

    cout << v.size() << '\n';

    for (auto pos : v)
    {
        cout << pos.first << " " << pos.second << '\n';
    }
}
