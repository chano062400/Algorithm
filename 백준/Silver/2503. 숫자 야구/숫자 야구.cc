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

struct info
{
    string num;
    int strike, ball;
};

pair<int, int> getscore(string cur, string target)
{
    int strike = 0, ball = 0;
    for (int i = 0; i < 3; i++)
    {
        if (cur[i] == target[i])
        {
            strike++;
        }
        else if (target.find(cur[i]) != string::npos)
        {
            ball++;
        }
    }

    return { strike, ball };
}

bool check(string num)
{
    return num[0] != num[1] && num[0] != num[2] && num[1] != num[2] && num.find('0') == string::npos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, res = 0;
    cin >> n;

    vector<info> v;
    for (int i = 0; i < n; i++)
    {
        string num;
        int strike, ball;
        cin >> num >> strike >> ball;
        v.push_back({ num,strike,ball });
    }

    for (int i = 123; i <= 987; i++)
    {
        string cur = to_string(i);
        // 중복 숫자가 없고, 0이 없어야 함.
        if (!check(cur)) continue;

        bool possible = true;
        for (const auto& information : v)
        {
            pair<int, int> score = getscore(cur, information.num);
            if (score.first != information.strike || score.second != information.ball)
            {
                possible = false;
                break;
            }
        }

        if (possible) res++;
    }

    cout << res;
}