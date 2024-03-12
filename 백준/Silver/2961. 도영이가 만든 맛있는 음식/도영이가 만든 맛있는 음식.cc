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
using namespace std;

int n;
long long res = 9999999999;
vector<pair<int, int>> taste, v;
bool visited[10];

void back(int size)
{
    if (v.size() == size)
    {
        long long sour = 1, bitter = 0;
        for (auto pair : v)
        {
            sour *= pair.first;
            bitter += pair.second;
        }

        res = min(res, abs(sour - bitter));

        return;
    }

    for (int i = 0; i < taste.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            v.push_back({ taste[i].first, taste[i].second });
            back(size);
            v.pop_back();
            visited[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i=0; i<n; i++)
    {
        int sour, bitter;
        cin >> sour >> bitter;
        taste.push_back({ sour, bitter });
    }

    for (int i = 1; i <= n; i++)
    {
        back(i);
    }

    cout << res;
}
