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

/*
    dp[h][w][0][0] - 동쪽으로 안꺾음
    dp[h][w][0][1] - 동쪽으로 꺾음
    dp[h][w][1][0] - 북쪽으로 안꺾음
    dp[h][w][1][1] - 북쪽으로 꺾음
*/
int dp[101][101][2][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int w, h;
    cin >> w >> h;

    for (int i = 1; i <= w; i++)
    {
        dp[1][i][0][0] = 1;
    }

    for (int i = 1; i <= h; i++)
    {
        dp[i][1][1][0] = 1;
    }

    for (int i = 2; i <= h; i++)
    {
        for (int j = 2; j <= w; j++)
        {
            // 동쪽으로 안꺾는 경우 = 전에 동쪽으로 꺾은 경우 + 안꺾은 경우
            dp[i][j][0][0] = (dp[i][j-1][0][0] + dp[i][j-1][0][1]) % 100000;
            
            // 동쪽으로 꺾는 경우 - 전에 북쪽으로 꺾지 않고 이동중인 경우
            dp[i][j][0][1] = dp[i][j-1][1][0] % 100000;

            // 북쪽으로 안꺾는 경우 - 전에 북쪽으로 꺾은 경우 + 안꺾은 경우
            dp[i][j][1][0] = (dp[i - 1][j][1][1] + dp[i - 1][j][1][0]) % 100000;

            // 북쪽으로 꺽는 경우 - 전에 동쪽으로 꺾지 않고 이동중인 경우
            dp[i][j][1][1] = dp[i - 1][j][0][0] % 100000;
        }
    }

    cout << (dp[h][w][0][0] + dp[h][w][0][1] + dp[h][w][1][0] + dp[h][w][1][1]) % 100000;
}
