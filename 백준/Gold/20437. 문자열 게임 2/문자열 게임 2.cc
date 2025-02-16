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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--)
    {
        int res1 = 10001, res2 = 0;
        
        string str;
        cin >> str;
        vector<vector<int>> alpha(27);
        for (int i = 0; i < str.size(); i++)
        {
            alpha[str[i] - 'a'].push_back(i);
        }

        int k;
        cin >> k;

        for (int i = 0; i < 26; i++)
        {
            // 각 문자별로 등장 횟수가 k 이상이면
            if (alpha[i].size() < k) continue;

            // 해당 위치 벡터에서 연속한 k개를 확인하여 길이를 계산
            for (int j = 0; j + k - 1 < alpha[i].size(); j++)
            {
                int len = alpha[i][j + k - 1] - alpha[i][j] + 1;

                res1 = min(res1, len);
                res2 = max(res2, len);
            }
        }
        if (res1 == 10001)
            cout << -1 << "\n";
        else
            cout << res1 << " " << res2 << "\n";
    }
}