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

int n, m, cnt;
vector<int> v;

// 최댓값 - 최솟값의 값이 최소인 값이 num. 
bool Count(int num)
{
    cnt = 1; // 이미 최댓값 - 최솟값이 mid인 구간이 1개 있음.
    int mn = v[0], mx = v[0];
    
    for (int i = 1; i < v.size(); i++)
    {
        mn = min(v[i], mn);
        mx = max(v[i], mx);

        // 최댓값 - 최솟값이 num보다 크다면 구간이 하나 더 생김.
        if (mx - mn > num)
        {
            cnt++;
            mn = mx = v[i];
        }
    }

    return cnt <= m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    int start = 0, end = *max_element(v.begin(), v.end()), res = end;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (Count(mid))
        {
            //최댓값 중 최솟값 업데이트
            if (res > mid) res = mid;
            end = mid - 1;
        }
        else start = mid + 1;
    }

    cout << res;
}
