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

int n, m, res = 0;
int arr[2001][2001], output[2001][2001] = { 0 };


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
     
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] = str[j-1] - '0';
        }
    }

    for (int i = 1; i <= m; i++) output[i][1] = arr[i][1];

    for (int j = 2; j <= n; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            int mx = 0;
            if (i - 1 >= 1) mx = max(mx, output[i - 1][j - 1]);
            mx = max(mx, output[i][j - 1]);
            if (i + 1 <= m) mx = max(mx, output[i + 1][j - 1]);

            output[i][j] = arr[i][j] + mx;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        res = max(res, output[i][n - 1]);
    }

    cout << res;
}
