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
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        v.push_back({ start,end });
    }

    sort(v.begin(), v.end());
    pq.push(v[0].second);

    for (int i = 1; i < n; i++)
    {
        while (!pq.empty() && pq.top() <= v[i].first) pq.pop();
        pq.push(v[i].second);
        res = max(res, (int)pq.size());
    }

    cout << res; 
}
