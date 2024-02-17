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

int n, cnt, res = 987654321;
string s, e, temp;

void SwitchOn(int index)
{
    if(index > 0) temp[index - 1] = temp[index - 1] == '0' ? '1' : '0';
    temp[index] = temp[index] == '0' ? '1' : '0';
    if(index < n) temp[index + 1] = temp[index + 1] == '0' ? '1' : '0';
}

void solve(int index)
{
    temp = s;
    cnt = 0;
    if (index == 0) // 첫번째 스위치를 누름.
    {
        temp[0] = temp[0] == '0' ? '1' : '0';
        temp[1] = temp[1] == '0' ? '1' : '0';
        cnt++;
    }

    for (int i = 1; i < n; i++)
    {
        if (temp[i - 1] != e[i - 1])
        {
            SwitchOn(i);
            cnt++;
        }
    }

    if (temp == e) res = min(res, cnt);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    cin >> s >> e;
    solve(0); // 첫번째 스위치를 누르고 시작.
    solve(1); // 첫번째 스위치를 누르지 않고 시작.

    if (res == 987654321) cout << -1;
    else cout << res;

};

