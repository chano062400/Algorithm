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
long long dp[65][10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n;

    for (int i = 0; i <= 9; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= 64; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int h = j; h <= 9; h++)
            {
                dp[i][j] += dp[i - 1][h];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        long long sum = 0;
        for (int j = 0; j <= 9; j++)
        {
            sum += dp[num][j];
        }

        cout << sum << '\n';
    }
};

