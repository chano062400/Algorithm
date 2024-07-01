#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int dp[1001][1001];
int MaxLen = 0;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= b; j++)
        {
            dp[i][j] = str[j-1] -'0';
        }
    }

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (dp[i][j] != 0)
            {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                MaxLen = max(MaxLen, dp[i][j]);
            }
        }
    }

    cout << MaxLen * MaxLen << '\n';
}