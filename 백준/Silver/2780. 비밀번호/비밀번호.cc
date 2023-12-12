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

long long num[1001][10], res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    
    for (int i = 0; i < 1001; i++)
    {
        num[1][i] = 1;
    }

    for (int i = 2; i < 1001; i++)
    {
        num[i][0] = num[i - 1][7] % 1234567;
        num[i][1] = (num[i - 1][2] + num[i - 1][4]) % 1234567;
        num[i][2] = (num[i - 1][1] + num[i - 1][3] + num[i - 1][5]) % 1234567;
        num[i][3] = (num[i - 1][2] + num[i - 1][6]) % 1234567;
        num[i][4] = (num[i - 1][1] + num[i - 1][5] + num[i - 1][7]) % 1234567;
        num[i][5] = (num[i - 1][2] + num[i - 1][4] + num[i - 1][6] + num[i - 1][8]) % 1234567;
        num[i][6] = (num[i - 1][3] + num[i - 1][5] + num[i - 1][9]) % 1234567;
        num[i][7] = (num[i - 1][4] + num[i - 1][8] + num[i - 1][0]) % 1234567;
        num[i][8] = (num[i - 1][5] + num[i - 1][7] + num[i - 1][9]) % 1234567;
        num[i][9] = (num[i - 1][6] + num[i - 1][8]) % 1234567;
    }

    for (int i = 0; i < n; i++)
    {
        int len;
        cin >> len;
        res = 0;

        for (int j = 0; j < 10; j++)
        {
            res += num[len][j] % 1234567;
        }

        cout << res % 1234567 << '\n';
    }
}
