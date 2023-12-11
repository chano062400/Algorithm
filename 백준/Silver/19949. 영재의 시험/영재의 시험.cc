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
using namespace std;

vector<int> v;
int num[10], ans = 0, res=0;

void back(int cnt)
{
    if (v.size() == 10)
    {
        ans = 0;
        for (int i = 0; i < 10; i++)
        {
            if (v[i] == num[i]) ans++;
        }
        if (ans >= 5)
        {
            res++;
        }
        return;
    }

    for (int i = 1; i <= 5; i++)
    {
        if (cnt > 1 && v[cnt - 2] == v[cnt - 1] && i == v[cnt - 1]) continue;
        v.push_back(i);
        back(cnt + 1);
        v.pop_back();   
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    for (int i = 0; i < 10; i++)
    {
        cin >> num[i];
    }

    back(0);

    cout << res;
}
