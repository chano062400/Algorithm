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

int n;
string dp[251];

string stringadd(string str1, string str2)
{
    string res = "";

    int idx1 = str1.length() - 1, idx2 = str2.length() - 1, roundnum = 0, sum =0;

    while (idx1 >= 0)
    {
        if (idx2 >= 0) sum = str1[idx1] - '0' + str2[idx2] - '0' + roundnum;
        else sum = str1[idx1] - '0' + roundnum;

        roundnum = sum >= 10 ? 1 : 0;
        res = to_string(sum % 10) + res;
        
        idx1--;
        idx2--;
    }

    return roundnum == 1 ? "1" + res : res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    dp[0] = "1";
    dp[1] = "1";
    dp[2] = "3";
    dp[3] = "5";
    
    for (int i = 4; i <= 250; i++)
    {
        dp[i] = stringadd(stringadd(dp[i - 2], dp[i - 2]), dp[i - 1]);
    }
    
    while (1)
    {
        cin >> n;
        if (cin.eof() == 1) break;
        cout << dp[n] << '\n';
    }
}
