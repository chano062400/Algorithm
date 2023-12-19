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
using namespace std;

int arr[301][301], dp[301][301];
int dx[2] = { 1,0 }; // 아래
int dy[2] = { 0,1 }; // 오른쪽

int n, m;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    cin >> n >> m;

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    dp[1][1] = arr[1][1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j + 1] == 1)
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + 1);
            else
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);

            if (arr[i + 1][j] == 1)
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
            else
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }

    cout << dp[n][m];

}
