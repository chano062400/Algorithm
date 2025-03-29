 #include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
#include <limits.h>
#include <list>
using namespace std;

int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int n;

bool cmp1(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first == p2.first) return p1.second > p2.second;
    return p1.first < p2.first;
}

bool cmp2(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second > p2.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    
    vector<pair<int,int>> v; 
    for (int i = 0; i < n; i++)
    {
        int m1, d1, m2, d2;
        cin >> m1 >> d1 >> m2 >> d2;

        int start = m1 * 100 + d1;
        int end = m2 * 100 + d2;
        v.push_back({ start, end });
    }

    sort(v.begin(), v.end(), cmp1);

    int start = 101, end = 301, res = 0, idx = 0;
    while (end < 1131 && !v.empty())
    {
        vector<pair<int, int>> temp;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first <= end && v[i].second > end)
            {
                temp.push_back(v[i]);
            }
            else if(v[i].first > end && v[i].second > end)
            {
                idx = i;
                break;
            }
        }

        if (temp.empty()) break;
        sort(temp.begin(), temp.end(), cmp2);
        end = temp[0].second;
        res++;
        v.erase(v.begin(), v.begin() + idx);
    }

    end > 1131 ? cout << res : cout << 0;
}