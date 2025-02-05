#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "memory.h"
#include <set>
#include <unordered_set>
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

int dice[10001][7], n;
// 1 6  2 4 3 5
vector<vector<int>> dices = { 
    // 원래
    {1,2,3,4,5,6},
    // 위
    {3,2,6,4,1,5},
    // 아래
    {5,2,1,4,6,3},
    // 왼쪽
    {4,1,3,6,5,2},
    // 오른쪽
    {2,6,3,1,5,4},
    // 위 아래 뒤집음
    {6,4,5,2,3,1}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            cin >> dice[i][j];
        }
    }

    int up = 1, down = 6, res = 0;
    for (int i = 0; i < 6; i++)
    {
        vector<int> downdice = dices[i];
        int sum = 0, mx = 0;

        // 아래 주사위의 윗면
        up = dice[1][downdice[0]];
        // 위 주사위의 아랫면
        down = dice[1][downdice[5]];

        for (int idx = 1; idx <= 4; idx++)
        {
            mx = max(mx,dice[1][downdice[idx]]);
        }
        sum += mx;
        
        for (int j = 2; j <= n; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                vector<int> updice = dices[k];
                
                down = dice[j][updice[5]];
                // 아래 주사위의 윗면과 위 주사위의 아랫면이 같아야 함.
                if (up != down) continue;
                
                up = dice[j][updice[0]];

                mx = 0;
                for (int idx2 = 1; idx2 <= 4; idx2++)
                {
                    mx = max(mx,dice[j][updice[idx2]]);
                }
                sum += mx;
                break;
            }
        }

        res = max(res, sum);
    }

    cout << res;
}