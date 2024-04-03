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

vector<pair<int, int>> v; // 학생 번호, 추천 수

void erase()
{
    int mn = 1001;
    for (int i = 0; i < v.size(); i++)
    {
        mn = min(mn, v[i].second);
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (mn == v[i].second)
        {
            v.erase(v.begin() + i);
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int num;
        cin >> num;

        bool IsIn = false;
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j].first == num)
            {
                v[j].second++;
                IsIn = true;
                break;
            }
        }

        if (!IsIn)
        {
            if (v.size() == n)
            {
                erase();
            }
            v.push_back({ num,1 });
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " ";
    }

}
