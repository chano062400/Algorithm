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


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
     
    int n, l;
    cin >> n >> l;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        v.push_back({ s, e });
    }

    sort(v.begin(), v.end());

    int start = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        // 현재 선의 끝 지점이 다음 선의 시작 지점보다 짧다면 갱신
        if (start - 1 < v[i].first)
        {
            start = v[i].first;
        }

        // 웅덩이를 다 덮을 때까지
        while (start < v[i].second)
        {
            start += l;
            res++;
        }
    }
    cout << res;
}
