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

int n;
long long arr[100001][3], dp[100001][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    while(1)
    {
        cin >> n;
        if (n == 0) break;
         
        memset(dp, 0, sizeof(dp));
        memset(arr, 0, sizeof(arr));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> arr[i][j];
            }
        }

        //dp[0][1]에서 출발하기 때문에 dp[1][0]이나 dp[1][1]에서 dp[0][0] 값을 가져오지 못하도록 큰 값으로 초기화해준다.
        dp[0][0] = 987654321; 
        dp[0][1] = arr[0][1];
        dp[0][2] = dp[0][1] + arr[0][2];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = min({dp[i - 1][j] + arr[i][j], dp[i - 1][j + 1] + arr[i][j] });
                }
                if (j == 1)
                {
                    dp[i][j] = min({dp[i][j - 1] + arr[i][j], dp[i - 1][j - 1] + arr[i][j], dp[i - 1][j] + arr[i][j], dp[i - 1][j + 1] + arr[i][j] });
                }
                if (j == 2)
                {
                    dp[i][j] = min({ dp[i][j - 1] + arr[i][j], dp[i - 1][j] + arr[i][j], dp[i - 1][j - 1] + arr[i][j] });
                }
            }
        }

        cout << tc << ". " << dp[n-1][1] << '\n';
        tc++;
    }
}
