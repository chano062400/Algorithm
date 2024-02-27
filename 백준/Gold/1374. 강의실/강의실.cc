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


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, res = 0;
    cin >> n;
    
    vector<pair<int, int>> v;
    while (n--)
    {
        int num, start, end;
        cin >> num >> start >> end;

        v.push_back({ start,end });
    }

    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<>> pq;
    pq.push(v[0].second);

    for (int i = 1; i < v.size(); i++)
    {
        if (pq.top() <= v[i].first)
        {
            pq.pop();
        }

        pq.push(v[i].second);

    }

    cout << pq.size();
}
